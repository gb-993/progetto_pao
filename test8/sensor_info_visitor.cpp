#include "sensor_info_visitor.h"

SensorInfoVisitor::SensorInfoVisitor() {}

QWidget* SensorInfoVisitor::getWidget() {
    return widget;
}

void SensorInfoVisitor::visitLight(Sensor_light& light) {
    widget = new QLabel("<b>Actual Status: </b>" + light.getInfo().at(4));
}

void SensorInfoVisitor::visitTemperature(Sensor_temperature& temp) {
    widget = new QLabel("<b>Upper Value: </b>" + temp.getInfo().at(4) + "<b> Lower Value: </b>" + temp.getInfo().at(5));
}

void SensorInfoVisitor::visitHumidity(Sensor_humidity& hum) {
    widget = new QLabel("<b>Upper Value: </b>" + hum.getInfo().at(4) + "<b> Lower Value: </b>" + hum.getInfo().at(5));
}

void SensorInfoVisitor::visitVolume(Sensor_volume& vol) {
    widget = new QLabel("<b>Upper Value: </b>" + vol.getInfo().at(4));
}
void SensorInfoVisitor::visitFilter(Sensor_filter& filter) {
    widget = new QLabel("<b>Number of filter changed: </b>" + filter.getInfo().at(4));
}
