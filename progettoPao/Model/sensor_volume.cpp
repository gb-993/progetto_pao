#include "sensor_volume.h"

Sensor_volume::Sensor_volume(QString n, QString t, QString e, double u): Sensor(n, t, e), upper(u) {}

// metodi get

double Sensor_volume::getUpper() const {
    return upper;
}
QList<QString> Sensor_volume::getInfo() const{
    QList<QString> list;
    list = Sensor::getInfo();
    list.append(QString::number(getUpper()));
    return list;
}

// metodo set e chiamata alla lista di osservatori
void Sensor_volume::setUpper(const double& u) {
    upper = u;
    notifyObservers(*this);
}

// ovveride per generare nuovi dati di simulazione a seconda del tipo di sensore
void Sensor_volume::genSimulation() {
    simulationData.clear();

    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    int val = 0;
    double x = 0.0;
    double y = upper;
    QList<QPointF> p;
    for(int i = 0; i < 100; i ++) {
        x += 1.0;
        val = generator.bounded(1,5);
        if ((y-val) >= 0){
            y -= val;
        } else {
            y = 0;
        }
        p.append(QPointF(x, y));
    }
    setSimulationData(p);
}

// chiama visitVolume sul visitor passato
void Sensor_volume::accept(SensorVisitorInterface& visitor) {
    visitor.visitVolume(*this);
}

// trasforma il sensore in un QJsonObject che lo rappresenta
QJsonObject Sensor_volume::sensorToJson() const {
    QJsonObject sensorObject = Sensor::sensorToJsonCommonField();
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
