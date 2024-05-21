#include "sensor_light.h"

Sensor_light::Sensor_light(QString n, QString t, QString e, bool s): Sensor(n, t, e), status(s) {}

int Sensor_light::getStatus() const {
    return status;
}

void Sensor_light::setStatus(const bool& s) {
    status = s;
}

void Sensor_light::print_sensor() const {
    qDebug()<<getId()<<getName()<<getType()<<getEnv()<<getStatus();
    if(has_simulation_data()){
        qDebug() << "Lista di punti: ";
        for (const QPointF &point : getSimData()) {
            qDebug() << "(" << point.x() << "," << point.y() << ")";
        }
    }
}

void Sensor_light::genSimulation() {
    //pulisce la lista della simulazione precedente
    simulationData.clear();

    //genera punti causali
    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    int x = 0;
    int y = 0;
    for(int i = 0; i < 100; i ++) {
        x += 1;
        y = generator.bounded(0,2);
        simulationData.append(QPointF(x, y)); // aggiunge il punto alla lista
    }
}

// applicato su un sensore, return un QJsonObject che è un singolo sensore in formato json
QJsonObject Sensor_light::sensorToJson(){
    // creo l'oggetto json che contiene i campi del sensore (name, type, id, simulationData)
    /*
    QJsonObject sensorObject;
    sensorObject["id"] = getId();
    sensorObject["name"] = getName();
    sensorObject["type"] = getType();
    sensorObject["environment"] = getEnv();
    */
    QJsonObject sensorObject = Sensor::sensorToJsonCommonField();
    sensorObject["status"] = getStatus();

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


Sensor_light* Sensor_light::jsonToSensor(const QJsonValue& sensorValue){
    // SENSOR <- RICEVE QUESTO "SENSOR VALUE"
    QJsonObject sensorObject = sensorValue.toObject();

    // Estrarre il nome e il tipo del sensore dall'oggetto JSON
    //int id = sensorObject["id"].toInt();
    QString name = sensorObject["name"].toString();
    QString type = sensorObject["type"].toString();
    QString environment = sensorObject["environment"].toString();

    bool status = sensorObject["status"].toBool();


    // Creare un nuovo sensore e aggiungerlo alla lista dei puntatori a sensori
    Sensor_light* sensor = new Sensor_light(name, type, environment, status);

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
