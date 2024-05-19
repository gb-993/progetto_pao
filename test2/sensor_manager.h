#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <QObject>
#include <QJsonObject>
#include <QList>
#include "Sensor.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>

class Sensor_manager : public QObject {
    Q_OBJECT
private:
    QList<Sensor*> all_sensors; // Lista dei sensori
public:
    Sensor_manager();
    // metodi get
    QList<Sensor *> getSensors() const;
    // Funzioni per la gestione dei sensori
    void addSensor(Sensor *sensor);
    void removeSensor(Sensor *sensor);
    void print_sensor_list();

    // serializer out
    QJsonObject sensorListToJson();
    // serializer in
    void loadDataFromJson(QFile&);
};

#endif // SENSORMANAGER_H
