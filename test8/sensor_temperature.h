#ifndef SENSOR_TEMPERATURE_H
#define SENSOR_TEMPERATURE_H

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

class Sensor_temperature: public Sensor {
private:
    double lower;
    double upper;
public:
    Sensor_temperature(QString ="default_name", QString ="temperature", QString ="tank", double =12.0, double =18.0);

    double getLower() const;
    double getUpper() const;
    QList<QString> getInfo() const;

    void setLower(const double&);
    void setUpper(const double&);

    void print_sensor() const;

    void genSimulation();

    // metodi Visitor
    void accept(SensorVisitorInterface&);

    QJsonObject sensorToJson();
    Sensor_temperature* jsonToSensor(const QJsonValue&);
};

#endif // SENSOR_TEMPERATURE_H
