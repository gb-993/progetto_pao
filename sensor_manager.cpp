// MODEL
// gestisce i sensori nel loro insieme, non si cura delle caratteristiche di ognuno
// circa come la classe Rubrica per i contatti
// forse ha senso farlo diventare direttamente una lista

#include "sensor_manager.h"

SensorManager::SensorManager() {
    // AGGIUNTA IO: inserisco 4 sensori di defalt
    /*all_sensors.append(new Sensor("s1","temp"));
    all_sensors.append(new Sensor("s2","hum"));
    all_sensors.append(new Sensor("s3","UV"));
    all_sensors.append(new Sensor("s4","acid"));*/
}

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

void SensorManager::print_sensor_list() {
    if(all_sensors.isEmpty()) {
        qDebug() <<"Lista vuota";
    }else{
        qDebug() << "Sensori nella lista:";
        for (Sensor* sensor : all_sensors) { // rifare il for
            qDebug() <<"Nome:" << sensor->getName() << " Tipo:" << sensor->getType();
        }
    }
}
