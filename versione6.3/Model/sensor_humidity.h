#ifndef SENSOR_HUMIDITY_H
#define SENSOR_HUMIDITY_H

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

class Sensor_humidity: public Sensor {
private:
    double lower;
    double upper;
public:
    Sensor_humidity(QString ="default_name", QString ="humidity", QString ="room", double =70.0, double =80.0);
    double getLower() const;
    double getUpper() const;
    QList<QString> getInfo() const;
    void setLower(const double&);
    void setUpper(const double&);
    void genSimulation();
    void accept(SensorVisitorInterface&);
    QJsonObject sensorToJson() const;
    virtual ~Sensor_humidity() {}
};

#endif // SENSOR_HUMIDITY_H
