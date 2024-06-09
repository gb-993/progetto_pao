#ifndef SENSOR_INFO_VISITOR_H
#define SENSOR_INFO_VISITOR_H

#include <QWidget>
#include <QLabel>
#include "../Model/sensor_visitor_interface.h"
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

class SensorInfoVisitor: public SensorVisitorInterface {
private:
    QLabel* label;
public:
    SensorInfoVisitor();
    QLabel* getLabel();
    void visitLight(Sensor_light&);
    void visitTemperature(Sensor_temperature&);
    void visitHumidity(Sensor_humidity&);
    void visitVolume(Sensor_volume&);
    void visitFilter(Sensor_filter&);
};

#endif // SENSOR_INFO_VISITOR_H
