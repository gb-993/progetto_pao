#ifndef SENSOR_VISITOR_INTERFACE_H
#define SENSOR_VISITOR_INTERFACE_H

class Sensor_light;
class Sensor_temperature;
class Sensor_humidity;
class Sensor_volume;
class Sensor_filter;

class SensorVisitorInterface {
public:
    virtual ~SensorVisitorInterface() = default;
    virtual void visitLight(Sensor_light& light) = 0;
    virtual void visitTemperature(Sensor_temperature& temp) = 0;
    virtual void visitHumidity(Sensor_humidity& hum) = 0;
    virtual void visitVolume(Sensor_volume& vol) = 0;
    virtual void visitFilter(Sensor_filter& filter) = 0;
};



#endif // SENSOR_VISITOR_INTERFACE_H
