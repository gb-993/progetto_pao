#include "sensor_manager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>

SensorManager::SensorManager() {}

void SensorManager::addSensor(Sensor *sensor) {
    if (sensor)
        all_sensors.append(sensor);
}

void SensorManager::removeSensor(Sensor *sensor) {
    if (sensor)
        all_sensors.removeOne(sensor); // removeOne rimuove la prima occorrenza trovata
}

// ATTENZIONE: controllare se serve copia profonda o no
QList<Sensor*> SensorManager::getSensors() const {
    return all_sensors;
}

// controllare se serve
//QList<Sensor*>& SensorManager::getSensorPointers() {
//    return all_sensors;
//}

// modificata in modo che stampi anche tutte le info dei sensori
void SensorManager::print_sensor_list() {
    if(all_sensors.isEmpty()) {
        qDebug() <<"Lista vuota";
    }else{
        qDebug() << "Sensori nella lista:";
        for (Sensor* sensor : all_sensors) {
            qDebug() <<"Nome:" << sensor->getName() << " Tipo:" << sensor->getType()<<sensor->getEnv()<<sensor->getId();;
            if(sensor->has_simulation_data()){
                qDebug() << "Lista di punti: ";
                for (const QPointF &point : sensor->getSimulationData()) {
                    qDebug() << "(" << point.x() << "," << point.y() << ")";
                }
            }
        }
    }
}

// crea il json_file finale
// "sensors" : [un array di sensori in formato json]
QJsonObject SensorManager::sensorListToJson(){
    QJsonObject dataObject;
    QJsonArray sensorsArray;

    for (Sensor* sensor : all_sensors) {
        sensorsArray.append(sensor->sensorToJson());
    }

    dataObject["sensors"] = sensorsArray;
    return dataObject;
}




void SensorManager::loadDataFromJson(QFile& file) {
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
        all_sensors.append(jsonToSensor(sensorValue));

    }

}


