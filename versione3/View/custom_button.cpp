#include "custom_button.h"

CustomButton::CustomButton(QString n, Sensor* s, QPushButton* parent): name(n), sensor(s), QPushButton(parent) {
    this->setText(name);

    // se faccio questa crasha WTFFFF
    //id = sensor->getId();

    disconnect(this, &CustomButton::clicked, this, &CustomButton::buttonClicked);
    connect(this, &CustomButton::clicked, this, &CustomButton::buttonClicked);
    //connect(this, &CustomButton::clicked, this, &CustomButton::showInfo);
    //connect(this, &CustomButton::clicked, this, &CustomButton::setUpModify);
}

void CustomButton::buttonClicked() {
    emit buttonClickedSignal(sensor);
}

void CustomButton::setSensor(Sensor* s) {
    sensor = s;
}

Sensor& CustomButton::getSensor() const {
    return *sensor;
}

int CustomButton::getId() const {
    return id;
}

void CustomButton::setName(QString s) {
    name = s;
}
