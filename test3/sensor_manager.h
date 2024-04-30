#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <QObject>
#include <QList>
#include "Sensor.h"

class Sensor_manager : public QObject {
    Q_OBJECT
private:
    QList<Sensor*> all_sensors; // Lista dei sensori
public:
    Sensor_manager();
    // metodi get
    QList<Sensor *> getSensors() const;
    QList<Sensor *> getSensorsTwo();
    // Funzioni per la gestione dei sensori
    void addSensor(Sensor *sensor);
    void removeSensor(Sensor *sensor);
    void print_sensor_list();
};

#endif // SENSOR_MANAGER_H
