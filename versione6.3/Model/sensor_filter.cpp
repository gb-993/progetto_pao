#include "sensor_filter.h"

Sensor_filter::Sensor_filter(QString n, QString t, QString e, int f): Sensor(n, t, e), filterChanged(f) {}

// metodi get

int Sensor_filter::getFil() const {
    return filterChanged;
}

QList<QString> Sensor_filter::getInfo() const {
    QList<QString> list;
    list = Sensor::getInfo();
    list.append(QString::number(getFil()));
    return list;
}

// metodo set e chiamata alla lista di osservatori

void Sensor_filter::setFil(const int& f) {
    filterChanged = f;
    notifyObservers(*this);
}

// ovveride per generare nuovi dati di simulazione a seconda del tipo di sensore
void Sensor_filter::genSimulation() {
    simulationData.clear();

    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    int val = 0;
    int x = 0;
    int y = 0;
    QList<QPointF> p;
    for(int i = 0; i < 100; i ++) {
        val = generator.bounded(1,4);
        x += 1.0;
        y += val;
        p.append(QPointF(x, y));
    }
    setSimulationData(p);
}

// chiama visitFilter sul visitor passato
void Sensor_filter::accept(SensorVisitorInterface& visitor) {
    visitor.visitFilter(*this);
}

// trasforma il sensore in un QJsonObject che lo rappresenta
QJsonObject Sensor_filter::sensorToJson() const {
    QJsonObject sensorObject = Sensor::sensorToJsonCommonField();
    sensorObject["Filter Changed"] = getFil();

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
