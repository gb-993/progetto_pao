#ifndef SENSOR_FILTER_H
#define SENSOR_FILTER_H

#include "sensor.h"

class Sensor_filter: public Sensor {
    Q_OBJECT
private:
    int filterChanged;
public:
    Sensor_filter(QString ="default_name", QString ="filter", QString ="tank", int =0);

    int getFil() const;
    void setFil(const int&);

    void print_sensor() const;

    void genSimulation();
};

#endif // SENSOR_FILTER_H
