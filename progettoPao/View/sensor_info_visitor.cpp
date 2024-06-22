#include "sensor_info_visitor.h"

SensorInfoVisitor::SensorInfoVisitor() {}

// ritorna la label
QLabel* SensorInfoVisitor::getLabel() const{
    return label;
}

// override dei metodi virtuali puri del visitor

void SensorInfoVisitor::visitLight(Sensor_light& light) {
    label = new QLabel("<b>Actual Status: </b>" + light.getInfo().at(4));
    label->setStyleSheet("color: #000080;");
}

void SensorInfoVisitor::visitTemperature(Sensor_temperature& temp) {
    label = new QLabel("<b>Lower Value: </b>" + temp.getInfo().at(4) + "<b> Upper Value: </b>" + temp.getInfo().at(5));
    label->setStyleSheet("color: #000080;");
}

void SensorInfoVisitor::visitHumidity(Sensor_humidity& hum) {
    label = new QLabel("<b>Lower Value: </b>" + hum.getInfo().at(4) + "<b> Upper Value: </b>" + hum.getInfo().at(5));
    label->setStyleSheet("color: #000080;");
}

void SensorInfoVisitor::visitVolume(Sensor_volume& vol) {
    label = new QLabel("<b>Upper Value: </b>" + vol.getInfo().at(4));
    label->setStyleSheet("color: #000080;");
}
void SensorInfoVisitor::visitFilter(Sensor_filter& filter) {
    label = new QLabel("<b>Number of filter changed: </b>" + filter.getInfo().at(4));
    label->setStyleSheet("color: #000080;");
}
