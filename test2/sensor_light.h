#ifndef SENSOR_LIGHT_H
#define SENSOR_LIGHT_H

#include "sensor.h"

class Sensor_light: public Sensor {
    Q_OBJECT
private:
    bool status;
public:
    Sensor_light(QString ="default_name", QString ="light", QString ="room", bool =false);

    int getStatus() const;
    void setStatus(const bool&);

    void print_sensor() const;

    void genSimulation();
};


#endif // SENSOR_LIGHT_H
