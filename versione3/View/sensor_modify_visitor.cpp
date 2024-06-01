#include "sensor_modify_visitor.h"

SensorModifyVisitor::SensorModifyVisitor() {}

QComboBox* SensorModifyVisitor::getMenu() {
    return menu;
}

QComboBox* SensorModifyVisitor::getMenu2() {
    return menu2;
}

void SensorModifyVisitor::visitLight(Sensor_light& light) {
    menu = new QComboBox();
    menu2 = new QComboBox();
    menu->setPlaceholderText("Change Status");
    menu->addItem("0");
    menu->addItem("1");
    menu2->hide();
}

void SensorModifyVisitor::visitTemperature(Sensor_temperature& temp) {
    menu = new QComboBox();
    menu2 = new QComboBox();
    menu->setPlaceholderText("Change Max Value");
    for(float i = 16.0; i <= 18.0; i+=0.3){
        menu->addItem(QString::number(i));
    }
    menu2->setPlaceholderText("Change Min Value");
    for(float i = 10.0; i <= 12.0; i+=0.3){
        menu2->addItem(QString::number(i));
    }
}

void SensorModifyVisitor::visitHumidity(Sensor_humidity& hum) {
    menu = new QComboBox();
    menu2 = new QComboBox();
    menu->setPlaceholderText("Change Max Value");
    for(float i = 78.0; i <= 80.0; i+=0.2){
        menu->addItem(QString::number(i));
    }
    menu2->setPlaceholderText("Change Min Value");
    for(float i = 70.0; i <= 72.0; i+=0.2){
        menu2->addItem(QString::number(i));
    }
}

void SensorModifyVisitor::visitVolume(Sensor_volume& vol) {
    menu = new QComboBox();
    menu2 = new QComboBox();
    menu->setPlaceholderText("Change Max Value");
    for(float i = 150.0; i <= 500.0; i+=50.0){
        menu->addItem(QString::number(i));
    }
    menu2->hide();
}
void SensorModifyVisitor::visitFilter(Sensor_filter& filter) {
    menu = new QComboBox();
    menu2 = new QComboBox();
    menu->setPlaceholderText("Change Filter Changed");
    for(int i = 0; i <= 3; ++i){
        menu->addItem(QString::number(i));
    }
    menu2->hide();
}
