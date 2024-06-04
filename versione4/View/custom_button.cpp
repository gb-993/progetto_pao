#include "custom_button.h"

CustomButton::CustomButton(QString n, Sensor* s, QPushButton* parent): name(n), sensor(s), QPushButton(parent) {
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

/*void CustomButton::setName(QString string) {
    this->setText(string);
}*/

Sensor& CustomButton::getSensor() const {
    return *sensor;
}
