#include "custom_button.h"

CustomButton::CustomButton(QString n, QPushButton* parent): name(n), QPushButton(parent) {
    this->setText(name);

    connect(this, &CustomButton::clicked, this, &CustomButton::showInfo);
    connect(this, &CustomButton::clicked, this, &CustomButton::setUpModify);
}

void CustomButton::showInfo() {
    emit showInfoSignal();
}
void CustomButton::setUpModify() {
    emit setUpModifySignal();
}


QString CustomButton::getName() const{
    return name;
}
