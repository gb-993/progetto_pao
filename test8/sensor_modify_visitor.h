#ifndef SENSOR_MODIFY_VISITOR_H
#define SENSOR_MODIFY_VISITOR_H

#include <QWidget>
#include <QComboBox>
//#include <QLineEdit>
#include <QLabel>
#include "sensor_visitor_interface.h"
#include "sensor_light.h"
#include "sensor_filter.h"
#include "sensor_humidity.h"
#include "sensor_temperature.h"
#include "sensor_volume.h"

class SensorModifyVisitor: public SensorVisitorInterface {
private:
    QComboBox* menu;
    QComboBox* menu2;
public:
    SensorModifyVisitor();
    QComboBox* getMenu();
    QComboBox* getMenu2();
    void visitLight(Sensor_light&);
    void visitTemperature(Sensor_temperature&);
    void visitHumidity(Sensor_humidity&);
    void visitVolume(Sensor_volume&);
    void visitFilter(Sensor_filter&);
};

#endif // SENSOR_MODIFY_VISITOR_H
