#include "sensors_list_layout.h"

SensorsListLayout::SensorsListLayout() :
    sensorsLabel(new QLabel("Create a sensor or upload a simulation")),
    searchBar(new QLineEdit()),
    layout(new QVBoxLayout()),
    buttonsLayout(new QVBoxLayout()) {
    setFixedWidth(200);

    sensorsLabel->setStyleSheet("color: #000080; font-size: 18px;");
    sensorsLabel->setWordWrap(true);
    sensorsLabel->setAlignment(Qt::AlignCenter);

    searchBar->setPlaceholderText("Search a sensor");
    searchBar->setStyleSheet("background-color: white; color: #000080; font-size: 12px;");

    layout->addWidget(searchBar, 0, Qt::AlignTop);
    layout->addWidget(sensorsLabel, 0, Qt::AlignTop);
    layout->addLayout(buttonsLayout);
    layout->addStretch();

    setLayout(layout);

    disconnect(searchBar, &QLineEdit::textChanged, this, &SensorsListLayout::searchTextChanged);
    connect(searchBar, &QLineEdit::textChanged, this, &SensorsListLayout::searchTextChanged);
}

void SensorsListLayout::addButton(Sensor* s) {
    sensorsLabel->hide();

    CustomButton* button = new CustomButton(s->getName());
    button->setSensor(s);
    buttonsList.append(button);
    button->setStyleSheet("background-color: white; color: #000080; font-size: 14px;");
    buttonsLayout->insertWidget(0, button, 0, Qt::AlignTop);

    disconnect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::showInfo);
    disconnect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::sendSensor);

    connect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::showInfo);
    connect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::sendSensor);

    // TROVARE MODO PER NON FARLO AGGIUNGERE OGNI VOLTA CHE VIENE CHIAMATA ADDBUTTON !!!!!!!!
    s->addObserver(this);
}

void SensorsListLayout::notify(Sensor& s) {
    for(auto list=buttonsList.begin(); list!=buttonsList.end(); list++){
        if((*list)->getSensor()->getId() == s.getId()){
            (*list)->setText(s.getName());
            break;
        }
    }
}

void SensorsListLayout::showInfo(QPointer<Sensor> s){
    emit showInfoSignal(s);
}

void SensorsListLayout::sendSensor(QPointer<Sensor> s){
    emit sendSensorSignal(s);
}

void SensorsListLayout::searchTextChanged(const QString &text) {
    for (int i = 0; i < buttonsLayout->count(); ++i) {
        QWidget *widget = buttonsLayout->itemAt(i)->widget();
        if (QPushButton *button = qobject_cast<QPushButton*>(widget)) {
            if (button->text().contains(text, Qt::CaseInsensitive)) {
                button->show();
            } else {
                button->hide();
            }
        }
    }
}

void SensorsListLayout::clearLayout() {
    QLayoutItem* item;
    while((item = buttonsLayout->takeAt(0)) != nullptr) {
        if(QWidget* widget = item->widget()) {
            if(qobject_cast<CustomButton*>(widget)) {
                buttonsLayout->removeWidget(widget);
                delete widget;
                widget = nullptr; // boh
            }
        }
        delete item;
        item = nullptr; // boh
    }
}


QList<CustomButton*>* SensorsListLayout::getButtonsList() {
    return &buttonsList; // copia profonda
}

QLabel* SensorsListLayout::getLabel() const {
    return sensorsLabel;
}

void SensorsListLayout::printListTest() const {
    for(auto button: buttonsList){
        button->print_test();
    }
}

void SensorsListLayout::removeOneButton(CustomButton* b) {
    buttonsList.removeOne(b);
}
