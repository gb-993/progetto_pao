#ifndef SENSOR_LIGHT_H
#define SENSOR_LIGHT_H

#include "sensor.h"

class Sensor_light: public Sensor {
private:
    bool status;
public:
    Sensor_light(QString ="default_name", QString ="light", QString ="room", bool =false);
    int getStatus() const;
    void setStatus(const bool&);
    QList<QString> getInfo() const;
    void genSimulation();
    void accept(SensorVisitorInterface&);
    QJsonObject sensorToJson() const;
    virtual ~Sensor_light() {}
};


#endif // SENSOR_LIGHT_H
