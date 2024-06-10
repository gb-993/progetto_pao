#include "custom_button.h"

CustomButton::CustomButton(QString n, QPushButton* parent): QPushButton(parent), name(n)  {
    this->setText(name);

    disconnect(this, &CustomButton::clicked, this, &CustomButton::buttonClicked);
    connect(this, &CustomButton::clicked, this, &CustomButton::buttonClicked);
}

// emette segnale quando viene premuto il CustomButton
void CustomButton::buttonClicked() {
    emit buttonClickedSignal(sensor);
}

// set del sensore
void CustomButton::setSensor(Sensor* s) {
    sensor = s;
}

// ritorna il sensore
QPointer<Sensor> CustomButton::getSensor() const {
    return sensor;
}
