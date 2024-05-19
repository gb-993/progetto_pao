#include "sensor_filter.h"

Sensor_filter::Sensor_filter(QString n, QString t, QString e, int f): Sensor(n, t, e), filterChanged(f) {}

int Sensor_filter::getFil() const {
    return filterChanged;
}

void Sensor_filter::setFil(const int& f) {
    filterChanged = f;
}

void Sensor_filter::print_sensor() const {
    qDebug()<<getId()<<getName()<<getType()<<getEnv()<<getFil();
    if(has_simulation_data()){
        qDebug() << "Lista di punti: ";
        for (const QPointF &point : getSimData()) {
            qDebug() << "(" << point.x() << "," << point.y() << ")";
        }
    }
}

void Sensor_filter::genSimulation() {
    //pulisce la lista della simulazione precedente
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
        p.append(QPointF(x, y)); // aggiunge il punto alla lista
    }
    setSimulationData(p);
}

// applicato su un sensore, return un QJsonObject che è un singolo sensore in formato json
QJsonObject Sensor_filter::sensorToJson(){
    // creo l'oggetto json che contiene i campi del sensore (name, type, id, simulationData)
    QJsonObject sensorObject;
    sensorObject["id"] = getId();
    sensorObject["name"] = getName();
    sensorObject["type"] = getType();
    sensorObject["environment"] = getEnv();

    sensorObject["filterChanged"] = getFil();

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


Sensor_filter* Sensor_filter::jsonToSensor(const QJsonValue& sensorValue){
    // SENSOR <- RICEVE QUESTO "SENSOR VALUE"
    QJsonObject sensorObject = sensorValue.toObject();

    // Estrarre il nome e il tipo del sensore dall'oggetto JSON
    //int id = sensorObject["id"].toInt();
    QString name = sensorObject["name"].toString();
    QString type = sensorObject["type"].toString();
    QString environment = sensorObject["environment"].toString();
    int filterChanged = sensorObject["filterChanged"].toInt();

    // Creare un nuovo sensore e aggiungerlo alla lista dei puntatori a sensori
    Sensor_filter* sensor = new Sensor_filter(name, type, environment, filterChanged);

    if (sensorObject.contains("simulationData")) {
        QJsonArray simulationDataArray = sensorObject["simulationData"].toArray();
        QList<QPointF> simulationData;
        for (const auto& pointValue : simulationDataArray) {
            QJsonObject pointObject = pointValue.toObject();
            qreal x = pointObject["x"].toDouble();
            qreal y = pointObject["y"].toDouble();
            simulationData.append(QPointF(x, y));
        }
        sensor->setSimulationData(simulationData);
    }
    return sensor;
}
