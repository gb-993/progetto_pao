#include "sensor_light.h"

Sensor_light::Sensor_light(QString n, QString t, QString e, bool s): Sensor(n, t, e), status(s) {}

// metodi get

int Sensor_light::getStatus() const {
    return status;
}

QList<QString> Sensor_light::getInfo() const{
    QList<QString> list;
    list = Sensor::getInfo();
    list.append(QString::number(getStatus()));
    return list;
}

// metodo set e chiamata alla lista di osservatori

void Sensor_light::setStatus(const bool& s) {
    status = s;
    notifyObservers(*this);
}

// ovveride per generare nuovi dati di simulazione a seconda del tipo di sensore
void Sensor_light::genSimulation() {
    simulationData.clear();

    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    int x = 0;
    int y = 0;
    for(int i = 0; i < 100; i ++) {
        x += 1;
        y = generator.bounded(0,2);
        simulationData.append(QPointF(x, y));
    }
}

// chiama visitLight sul visitor passato
void Sensor_light::accept(SensorVisitorInterface& visitor) {
    visitor.visitLight(*this);
}

// trasforma il sensore in un QJsonObject che lo rappresenta
QJsonObject Sensor_light::sensorToJson() const {
    QJsonObject sensorObject = Sensor::sensorToJsonCommonField();
    sensorObject["Light Status"] = getStatus();

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
