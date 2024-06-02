#ifndef SENSOR_CONTROLLER_VISITOR_H
#define SENSOR_CONTROLLER_VISITOR_H

#include <QWidget>
#include "../Model/sensor_visitor_interface.h"
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

class SensorControllerVisitor: public SensorVisitorInterface {
private:
    QString menu;
    QString menu2;
public:
    SensorControllerVisitor(QString, QString);
    //QLabel* getLabel();
    void visitLight(Sensor_light&);
    void visitTemperature(Sensor_temperature&);
    void visitHumidity(Sensor_humidity&);
    void visitVolume(Sensor_volume&);
    void visitFilter(Sensor_filter&);
};

#endif // SENSOR_CONTROLLER_VISITOR_H
