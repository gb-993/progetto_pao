#ifndef SENSOR_FILTER_H
#define SENSOR_FILTER_H

#include "sensor.h"

class Sensor_filter: public Sensor {
private:
    int filterChanged;
public:
    Sensor_filter(QString ="default_name", QString ="filter", QString ="tank", int =0);
    int getFil() const;
    QList<QString> getInfo() const;
    void setFil(const int&);
    void genSimulation();
    void accept(SensorVisitorInterface&);
    QJsonObject sensorToJson() const;
    virtual ~Sensor_filter() {}
};

#endif // SENSOR_FILTER_H
