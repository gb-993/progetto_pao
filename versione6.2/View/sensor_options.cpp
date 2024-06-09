#include "sensor_options.h"

SensorOptions::SensorOptions(QWidget* parent): QWidget(parent) {

    buttonsLayout = new QVBoxLayout();
    modify = new QPushButton("Modify");
    deleteButton = new QPushButton("Delete");
    start_simulation = new CustomButton("New Simulation");

    // Setto caratteristiche TopLayout
    setFixedWidth(210);

    // Setto caratteristiche bottoni
    modify->setStyleSheet("background-color: white; color: #000080; font-size: 16px;");
    modify->setFixedWidth(195);
    deleteButton->setStyleSheet("background-color: white; color: #000080; font-size: 16px;");
    deleteButton->setFixedWidth(195);
    start_simulation->setStyleSheet("background-color: white; color: #000080; font-size: 16px;");
    start_simulation->setFixedWidth(195);

    // Aggiungo bottoni al layout
    buttonsLayout->addWidget(modify);
    buttonsLayout->addWidget(deleteButton);
    buttonsLayout->addWidget(start_simulation);
    buttonsLayout->addStretch(); // Per avere in alto
    buttonsLayout->setAlignment(Qt::AlignHCenter);

    setLayout(buttonsLayout);

    disconnect(modify, &QPushButton::clicked, this, &SensorOptions::showModifyWindow);
    disconnect(deleteButton, &QPushButton::clicked, this, &SensorOptions::showDeleteWindow);
    disconnect(start_simulation, &CustomButton::buttonClickedSignal, this, &SensorOptions::startNewSimulation);

    connect(modify, &QPushButton::clicked, this, &SensorOptions::showModifyWindow);
    connect(deleteButton, &QPushButton::clicked, this, &SensorOptions::showDeleteWindow);
    connect(start_simulation, &CustomButton::buttonClickedSignal, this, &SensorOptions::startNewSimulation);
}

void SensorOptions::setUpButtonOptions(Sensor* s) {
    start_simulation->setSensor(s);
}

void SensorOptions::showModifyWindow() {
    emit showModifyWindowSignal();
}

void SensorOptions::showDeleteWindow() {
    emit showDeleteWindowSignal();
}

void SensorOptions::startNewSimulation(QPointer<Sensor> s) {
    emit startNewSimulationSignal(s);
}



