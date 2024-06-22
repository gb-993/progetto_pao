#include "sensor_manager.h"

Sensor_manager::Sensor_manager() {}

// aggiunge un sensore alla lista
void Sensor_manager::addSensor(Sensor *sensor) {
    all_sensors.append(sensor);
}

// riomuove un singolo sensore dalla lista
void Sensor_manager::removeSensor(Sensor *sensor) {
    if (sensor)
        all_sensors.removeOne(sensor);
}

// elimina tutti i sensori della lista
void Sensor_manager::removeAllSensor() {
    if(all_sensors.isEmpty()) {
        return;
    }else{
        for (Sensor* sensor : all_sensors) {
            all_sensors.removeOne(sensor);
            delete sensor;
            sensor = nullptr;
        }
    }
}

// ritorna la lista dei sensori
QList<Sensor*> Sensor_manager::getSensors() const {
    return all_sensors;
}

// trasforma la lista dei sensori in un qjson array di qjsonobject
QJsonObject Sensor_manager::sensorListToJson() const {
    QJsonObject dataObject;
    QJsonArray sensorsArray;
    for (Sensor* sensor : all_sensors) {
        sensorsArray.append(sensor->sensorToJson());
    }
    dataObject["sensors"] = sensorsArray;
    return dataObject;
}

// trasforma un qjsonobject in un sensore da aggiungere alla lista di sensori
void Sensor_manager::loadDataFromJson(QFile& file) {
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument loadDoc(QJsonDocument::fromJson(jsonData));
    QJsonObject dataObject = loadDoc.object();

    QJsonArray sensorsArray = dataObject["sensors"].toArray();

    for (const QJsonValue& sensorValue : sensorsArray) {
        all_sensors.append(Sensor_generator::jsonToSensor(sensorValue));
    }
}
