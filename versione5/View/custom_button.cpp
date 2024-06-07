#include "custom_button.h"

CustomButton::CustomButton(QString n, QPushButton* parent): name(n), QPushButton(parent) {
    this->setText(name);

    //sensor = nullptr;

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

void CustomButton::deleteSensorPointer() {
    //delete sensor;
    //sensor = nullptr;
}

void CustomButton::print_test() const {
    qDebug()<< "Test stampa";

}
