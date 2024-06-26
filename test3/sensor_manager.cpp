#include "sensor_manager.h"

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
        all_sensors.removeOne(sensor);
}

// ATTENZIONE: controllare se serve copia profonda o no
QList<Sensor*> Sensor_manager::getSensors() const {
    return all_sensors;
}
QList<Sensor*> Sensor_manager::getSensorsTwo() {
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
