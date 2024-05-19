#include "sensor_manager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <sensor_generator.h>

Sensor_manager::Sensor_manager() {
    // AGGIUNTA IO: inserisco 4 sensori di defalt
    /*all_sensors.append(new Sensor("s1","temp"));
    all_sensors.append(new Sensor("s2","hum"));
    all_sensors.append(new Sensor("s3","UV"));
    all_sensors.append(new Sensor("s4","acid"));*/
}

void Sensor_manager::addSensor(Sensor *sensor) {
    if (sensor)
        all_sensors.append(sensor);
}

void Sensor_manager::removeSensor(Sensor *sensor) {
    if (sensor)
        all_sensors.removeOne(sensor); // removeOne rimuove la prima occorrenza trovata --> INFORMARMI
}

// ATTENZIONE: controllare se serve copia profonda o no
QList<Sensor*> Sensor_manager::getSensors() const {
    return all_sensors;
}

void Sensor_manager::print_sensor_list() {
    if(all_sensors.isEmpty()) {
        qDebug() <<"Lista vuota";
    }else{
        qDebug() << "Sensori nella lista:";
        for (Sensor* sensor : all_sensors) {
            sensor->print_sensor();
        }
    }
}

// crea il json_file finale
// "sensors" : [un array di sensori in formato json]
QJsonObject Sensor_manager::sensorListToJson(){
    QJsonObject dataObject;
    QJsonArray sensorsArray;

    for (Sensor* sensor : all_sensors) {
        sensorsArray.append(sensor->sensorToJson());
    }

    dataObject["sensors"] = sensorsArray;
    return dataObject;
}




void Sensor_manager::loadDataFromJson(QFile& file) {
    /*
    // CONTROLLER
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        // Errore se non è possibile aprire il file
        qWarning() << "Impossibile aprire il file per la lettura:" << file.errorString();
        return;
    }
*/
    // Leggi i dati JSON dal file
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument loadDoc(QJsonDocument::fromJson(jsonData));
    QJsonObject dataObject = loadDoc.object();

    QJsonArray sensorsArray = dataObject["sensors"].toArray();

    for (const QJsonValue& sensorValue : sensorsArray) {
        all_sensors.append(Sensor_generator::jsonToSensor(sensorValue));

    }

}

