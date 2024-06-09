#include "sensor_controller_visitor.h"

SensorControllerVisitor::SensorControllerVisitor(QString m, QString m2): menu(m), menu2(m2)  {}

// override dei metodi virtuali puri del visitor: set dei parametri specifici modificati in base al tipo di sensore

void SensorControllerVisitor::visitLight(Sensor_light& light) {
    if(menu != "")
        light.setStatus(menu.toInt());
}

void SensorControllerVisitor::visitTemperature(Sensor_temperature& temp) {
    if(menu != "")
        temp.setUpper(menu.toDouble());
    if(menu2 != "")
        temp.setLower(menu2.toDouble());
}

void SensorControllerVisitor::visitHumidity(Sensor_humidity& hum) {
    if(menu != "")
        hum.setUpper(menu.toDouble());
    if(menu2 != "")
        hum.setLower(menu2.toDouble());
}

void SensorControllerVisitor::visitVolume(Sensor_volume& vol) {
    if(menu != "")
        vol.setUpper(menu.toDouble());
}
void SensorControllerVisitor::visitFilter(Sensor_filter& filter) {
    if(menu != "")
        filter.setFil(menu.toInt());
}
