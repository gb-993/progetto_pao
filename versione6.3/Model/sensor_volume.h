#ifndef SENSOR_VOLUME_H
#define SENSOR_VOLUME_H

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

class Sensor_volume: public Sensor {
private:
    double upper;
public:
    Sensor_volume(QString ="default_name", QString ="volume", QString ="tank", double =200.0);
    double getUpper() const;
    QList<QString> getInfo() const;
    void setUpper(const double&);
    void genSimulation();
    void accept(SensorVisitorInterface&);
    QJsonObject sensorToJson() const;
    virtual ~Sensor_volume() {}
};


#endif // SENSOR_VOLUME_H
