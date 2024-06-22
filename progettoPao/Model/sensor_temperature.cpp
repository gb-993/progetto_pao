#include "sensor_temperature.h"

Sensor_temperature::Sensor_temperature(QString n, QString t, QString e, double l, double u): Sensor(n, t, e), lower(l), upper(u) {}

// metodi get

double Sensor_temperature::getLower() const {
    return lower;
}

double Sensor_temperature::getUpper() const {
    return upper;
}

QList<QString> Sensor_temperature::getInfo() const{
    QList<QString> list;
    list = Sensor::getInfo();
    list.append(QString::number(getLower()));
    list.append(QString::number(getUpper()));
    return list;
}

// metodi set e chiamata alla lista di osservatori

void Sensor_temperature::setLower(const double& l) {
    lower = l;
    notifyObservers(*this);
}

void Sensor_temperature::setUpper(const double& u) {
    upper = u;
    notifyObservers(*this);
}

// ovveride per generare nuovi dati di simulazione a seconda del tipo di sensore
void Sensor_temperature::genSimulation() {
    simulationData.clear();

    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    double x = 0.0;
    double y = 0.0;
    QList<QPointF> p;
    for(int i = 0; i < 100; i ++) {
        x += 1.0;
        y = generator.bounded(int(lower),int(upper+1));
        p.append(QPointF(x, y));
    }
    setSimulationData(p);
}

// chiama visitTemperature sul visitor passato
void Sensor_temperature::accept(SensorVisitorInterface& visitor) {
    visitor.visitTemperature(*this);
}

// trasforma il sensore in un QJsonObject che lo rappresenta
QJsonObject Sensor_temperature::sensorToJson() const{
    QJsonObject sensorObject = Sensor::sensorToJsonCommonField();
    sensorObject["Min Value"] = getLower();
    sensorObject["Max Value"] = getUpper();

    if (has_simulation_data()) {
        QJsonArray simulationDataArray;
        const QList<QPointF>& dati_simulazione = getSimData();
        for (const auto& point : dati_simulazione) {
            QJsonObject pointObject;
            pointObject["x"] = point.x();
            pointObject["y"] = point.y();
            simulationDataArray.append(pointObject);
        }
        sensorObject["simulationData"] = simulationDataArray;
    }
    return sensorObject;
}

