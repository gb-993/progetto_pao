#include "custom_button.h"

CustomButton::CustomButton(Sensor* s, QPushButton* parent): sensor(s), QPushButton(parent) {
    this->setText(s->getName());

    connect(this, &CustomButton::clicked, [this](){this->showInfo(this->sensor);});
    connect(this, &CustomButton::clicked, [this]() {this->setUpModify(this->sensor);});
}

void CustomButton::showInfo(Sensor* s) {
    emit showInfoSignal(s);
    //s->print_sensor();
}
void CustomButton::setUpModify(Sensor* s) {
    emit setUpModifySignal(s);
}

QString CustomButton::getName() const{
    return this->getName();
}

Sensor* CustomButton::getSensor() const{
    return this->sensor;
}
