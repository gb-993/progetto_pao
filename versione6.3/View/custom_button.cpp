#include "custom_button.h"

CustomButton::CustomButton(QString n, QPushButton* parent): QPushButton(parent), name(n)  {
    this->setText(name);

    disconnect(this, &CustomButton::clicked, this, &CustomButton::buttonClicked);
    connect(this, &CustomButton::clicked, this, &CustomButton::buttonClicked);
}

void CustomButton::buttonClicked() {
    emit buttonClickedSignal(sensor);
}

void CustomButton::setSensor(Sensor* s) {
    sensor = s;
}

QPointer<Sensor> CustomButton::getSensor() const {
    return sensor;
}
