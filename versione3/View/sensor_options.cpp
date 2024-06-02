#include "sensor_options.h"

SensorOptions::SensorOptions(): buttonsLayout(new QVBoxLayout()), modify(new QPushButton("Modify")),
    deleteButton(new QPushButton("Delete")), start_simulation(new QPushButton("New Simulation")), confirmWindow(new ConfirmDeleteWindow()){
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

    //connect(modify, &QPushButton::clicked, modifyWindow, &ModifySensorWindow::exec);
    //connect(button, &QPushButton::clicked, [this, s](){ this->showInfo(s); });

    disconnect(modify, &QPushButton::clicked, this, &SensorOptions::showModifyWindow);
    disconnect(deleteButton, &QPushButton::clicked, confirmWindow, &ConfirmDeleteWindow::exec);
    connect(modify, &QPushButton::clicked, this, &SensorOptions::showModifyWindow);
    connect(deleteButton, &QPushButton::clicked, confirmWindow, &ConfirmDeleteWindow::exec);
}

void SensorOptions::showModifyWindow(){
    emit showModifyWindowSignal();
}



