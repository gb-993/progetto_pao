#include "sensor_options.h"

SensorOptions::SensorOptions(QWidget* parent): QWidget(parent) {

    buttonsLayout = new QVBoxLayout();
    modify = new QPushButton(QIcon(":/icons/pencil.svg"), "  Modify");
    deleteButton = new QPushButton(QIcon(":/icons/trash.svg"), "  Delete");
    start_simulation = new CustomButton(QIcon(":/icons/data.svg"), "  New Simulation");

    setFixedWidth(210);

    modify->setStyleSheet("background-color: white; color: #000080; font-size: 16px;");
    modify->setFixedWidth(195);
    deleteButton->setStyleSheet("background-color: white; color: #000080; font-size: 16px;");
    deleteButton->setFixedWidth(195);
    start_simulation->setStyleSheet("background-color: white; color: #000080; font-size: 16px;");
    start_simulation->setFixedWidth(195);

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

// setta il sensore passato nel CustomButton start_simulation
void SensorOptions::setUpButtonOptions(Sensor* s) {
    start_simulation->setSensor(s);
}

// emette segnale per mostrare la finestra di modifica
void SensorOptions::showModifyWindow() {
    emit showModifyWindowSignal();
}

// emette segnale per mostrare la finestra di eliminazione
void SensorOptions::showDeleteWindow() {
    emit showDeleteWindowSignal();
}

// emette segnale per avviare una nuova simulazione
void SensorOptions::startNewSimulation(QPointer<Sensor> s) {
    emit startNewSimulationSignal(s);
}



