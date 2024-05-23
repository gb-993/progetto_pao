#ifndef SENSOR_INFO_VISITOR_H
#define SENSOR_INFO_VISITOR_H

#include <QWidget>
#include <QLabel>
#include "sensor_visitor_interface.h"
#include "sensor_light.h"
#include "sensor_filter.h"
#include "sensor_humidity.h"
#include "sensor_temperature.h"
#include "sensor_volume.h"

class SensorInfoVisitor: public SensorVisitorInterface {
private:
    QWidget* widget;

public:
    SensorInfoVisitor();
    QWidget* getWidget();
    void visitLight(Sensor_light&);
    void visitTemperature(Sensor_temperature&);
    void visitHumidity(Sensor_humidity&);
    void visitVolume(Sensor_volume&);
    void visitFilter(Sensor_filter&);
};

#endif // SENSOR_INFO_VISITOR_H
