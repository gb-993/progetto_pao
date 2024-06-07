#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <QObject>
#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include "sensor_generator.h"
#include "sensor.h"

class Sensor_manager {
private:
    QList<Sensor*> all_sensors; // Lista dei sensori
public:
    Sensor_manager();
    // metodi get
    QList<Sensor *> getSensors() const;
    // Funzioni per la gestione dei sensori
    void addSensor(Sensor *sensor);
    void removeSensor(Sensor *sensor);
    void removeAllSensor();
    void print_sensor_list();

    // serializer out
    QJsonObject sensorListToJson();
    // serializer in
    void loadDataFromJson(QFile&);
};

#endif // SENSORMANAGER_H
