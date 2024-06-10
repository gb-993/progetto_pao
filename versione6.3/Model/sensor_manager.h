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
    QList<Sensor*> all_sensors;
public:
    Sensor_manager();
    QList<Sensor *> getSensors() const;
    void addSensor(Sensor*);
    void removeSensor(Sensor*);
    void removeAllSensor();
    QJsonObject sensorListToJson() const;
    void loadDataFromJson(QFile&);
};

#endif // SENSORMANAGER_H
