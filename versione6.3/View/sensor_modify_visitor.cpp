#include "sensor_modify_visitor.h"

SensorModifyVisitor::SensorModifyVisitor() {}

QComboBox* SensorModifyVisitor::getMenu() {
    return menu;
}

QComboBox* SensorModifyVisitor::getMenu2() {
    return menu2;
}

void SensorModifyVisitor::visitLight(Sensor_light&) {
    menu = new QComboBox();
    menu2 = new QComboBox();
    menu->setPlaceholderText("Change status");
    menu->addItem("0");
    menu->addItem("1");
    menu2->hide();
}

void SensorModifyVisitor::visitTemperature(Sensor_temperature&) {
    menu = new QComboBox();
    menu2 = new QComboBox();
    menu->setPlaceholderText("Change max value");
    for(float i = 16.0; i <= 18.0; i+=0.3){
        menu->addItem(QString::number(i));
    }
    menu2->setPlaceholderText("Change min value");
    for(float i = 10.0; i <= 12.0; i+=0.3){
        menu2->addItem(QString::number(i));
    }
}

void SensorModifyVisitor::visitHumidity(Sensor_humidity&) {
    menu = new QComboBox();
    menu2 = new QComboBox();
    menu->setPlaceholderText("Change max value");
    for(float i = 78.0; i <= 80.0; i+=0.2){
        menu->addItem(QString::number(i));
    }
    menu2->setPlaceholderText("Change min value");
    for(float i = 70.0; i <= 72.0; i+=0.2){
        menu2->addItem(QString::number(i));
    }
}

void SensorModifyVisitor::visitVolume(Sensor_volume&) {
    menu = new QComboBox();
    menu2 = new QComboBox();
    menu->setPlaceholderText("Change max value");
    for(float i = 150.0; i <= 500.0; i+=50.0){
        menu->addItem(QString::number(i));
    }
    menu2->hide();
}
void SensorModifyVisitor::visitFilter(Sensor_filter&) {
    menu = new QComboBox();
    menu2 = new QComboBox();
    menu->setPlaceholderText("Change number of filter changed");
    for(int i = 0; i <= 3; ++i){
        menu->addItem(QString::number(i));
    }
    menu2->hide();
}
