// MODEL
// gestisce i sensori nel loro insieme, non si cura delle caratteristiche di ognuno
// circa come la classe Rubrica per i contatti
// forse ha senso farlo diventare direttamente una lista

#include "sensor_manager.h"

SensorManager::SensorManager(): all_sensors() {}

void SensorManager::addSensor(Sensor *sensor) {
    if (sensor)
        all_sensors.append(sensor);
}

void SensorManager::removeSensor(Sensor *sensor) {
    if (sensor)
        all_sensors.removeOne(sensor);    // removeOne rimuove la prima occorrenza trovata
}

QList<Sensor *> SensorManager::getSensors() const {
    return all_sensors;
}

void SensorManager::print_sensor_list() {
    if(all_sensors.isEmpty()) {
        qDebug() <<"Lista vuota";
    }else{
        qDebug() << "Sensori nella lista:";
        for (Sensor* sensor : all_sensors) {
            qDebug() <<"Nome:" << sensor->getName() << " Tipo:" << sensor->getType();
        }
}
