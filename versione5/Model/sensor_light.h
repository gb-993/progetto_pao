#ifndef SENSOR_LIGHT_H
#define SENSOR_LIGHT_H

#include <QString>
#include <QList>
#include <QPointF>
#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QRandomGenerator>
#include <QJsonValue>
#include "sensor.h"

class Sensor_light: public Sensor {
private:
    bool status;
public:
    Sensor_light(QString ="default_name", QString ="light", QString ="room", bool =false);

    int getStatus() const;
    void setStatus(const bool&);
    QList<QString> getInfo() const;

    void print_sensor() const;

    void genSimulation();

    // metodi Visitor
    void accept(SensorVisitorInterface&);

    QJsonObject sensorToJson();
    Sensor_light* jsonToSensor(const QJsonValue&);

    virtual ~Sensor_light() {}


};


#endif // SENSOR_LIGHT_H
