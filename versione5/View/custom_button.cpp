#include "custom_button.h"

CustomButton::CustomButton(QString n, QPushButton* parent): name(n), QPushButton(parent) {
    this->setText(name);

    sensor = nullptr;

    disconnect(this, &CustomButton::clicked, this, &CustomButton::buttonClicked);
    connect(this, &CustomButton::clicked, this, &CustomButton::buttonClicked);
}

void CustomButton::buttonClicked() {
    emit buttonClickedSignal(sensor);
}

void CustomButton::setSensor(Sensor* s) {
    sensor = s;
}

Sensor* CustomButton::getSensor() const {
    return sensor;
}

void CustomButton::deleteSensorPointer() {
    delete sensor;
    sensor = nullptr;
}
