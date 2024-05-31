#ifndef SENSOR_GENERATOR_H
#define SENSOR_GENERATOR_H

#include "sensor.h"
#include "sensor_filter.h"
#include "sensor_humidity.h"
#include "sensor_light.h"
#include "sensor_temperature.h"
#include "sensor_volume.h"

class Sensor_generator {
    friend class Sensor_filter;
    friend class Sensor_humidity;
    friend class Sensor_light;
    friend class Sensor_temperature;
    friend class Sensor_volume;
public:
    static Sensor* jsonToSensor(const QJsonValue& sensorValue);
};

#endif // SENSOR_GENERATOR_H
