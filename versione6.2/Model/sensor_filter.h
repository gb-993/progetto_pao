#ifndef SENSOR_FILTER_H
#define SENSOR_FILTER_H

#include <QJsonValue>
#include <QString>
#include <QList>
#include <QPointF>
#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QRandomGenerator>
#include "sensor.h"

class Sensor_filter: public Sensor {
private:
    int filterChanged;
public:
    Sensor_filter(QString ="default_name", QString ="filter", QString ="tank", int =0);

    int getFil() const;
    QList<QString> getInfo() const;
    void setFil(const int&);

    void print_sensor() const;

    void genSimulation();

    // metodi Visitor
    void accept(SensorVisitorInterface&);

    QJsonObject sensorToJson();
    Sensor_filter* jsonToSensor(const QJsonValue&);

    virtual ~Sensor_filter() {}
};

#endif // SENSOR_FILTER_H
