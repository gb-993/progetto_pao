#include "custom_button.h"

CustomButton::CustomButton(QString n, QPushButton* parent): name(n), QPushButton(parent) {
    this->setText(name);

    connect(this, &CustomButton::clicked, this, &CustomButton::showInfo);
}

void CustomButton::showInfo() {
    emit showInfoSignal();
}
