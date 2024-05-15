#ifndef SENSOR_VOLUME_H
#define SENSOR_VOLUME_H

#include "sensor.h"

class Sensor_volume: public Sensor {
    Q_OBJECT
private:
    double lower;
    double upper;
public:
    Sensor_volume(QString ="default_name", QString ="volume", QString ="tank", double =0.0, double =200.0);

    double getLower() const;
    double getUpper() const;

    void setLower(const double&);
    void setUpper(const double&);

    void print_sensor() const;

    void genSimulation();
};

#endif // SENSOR_VOLUME_H
