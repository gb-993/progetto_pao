#ifndef SENSOR_OBSERVER_INTERFACE_H
#define SENSOR_OBSERVER_INTERFACE_H

class Sensor;

class Sensor_observer_interface {
    //Q_OBJECT
public:
    virtual ~Sensor_observer_interface() =default;
    virtual void notify(Sensor&) =0;
};

#endif // SENSOR_OBSERVER_INTERFACE_H
