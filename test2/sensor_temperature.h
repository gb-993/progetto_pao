#ifndef SENSOR_TEMPERATURE_H
#define SENSOR_TEMPERATURE_H

#include "sensor.h"

class Sensor_temperature: public Sensor {
    Q_OBJECT
private:
    double lower;
    double upper;
public:
    Sensor_temperature(QString ="default_name", QString ="temperature", QString ="tank", double =10.0, double =14.0); // valori 10 e 14 riguardano la temperatura della cantina, non del liquido dentro la botte

    double getLower() const;
    double getUpper() const;

    void setLower(const double&);
    void setUpper(const double&);

    void print_sensor() const;

    void genSimulation();
};

#endif // SENSOR_TEMPERATURE_H
