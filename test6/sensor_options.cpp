#include "sensor_options.h"

SensorOptions::SensorOptions(): buttonsLayout(new QVBoxLayout()), modify(new QPushButton("Modifica")), deleteButton(new QPushButton("Elimina")), start_simulation(new QPushButton("Avvia Simulazione")) {
    // Setto caratteristiche TopLayout
    setStyleSheet("background-color: purple;");
    setFixedWidth(210);

    // Setto caratteristiche bottoni
    modify->setStyleSheet("background-color: white; color: red; font-size: 17px;");
    modify->setFixedWidth(195);
    deleteButton->setStyleSheet("background-color: white; color: red; font-size: 17px;");
    deleteButton->setFixedWidth(195);
    start_simulation->setStyleSheet("background-color: white; color: red; font-size: 17px;");
    start_simulation->setFixedWidth(195);

    // Aggiungo bottoni al layout
    buttonsLayout->addWidget(modify);
    buttonsLayout->addWidget(deleteButton);
    buttonsLayout->addWidget(start_simulation);
    buttonsLayout->addStretch(); // Per avere in alto
    buttonsLayout->setAlignment(Qt::AlignHCenter);

    setLayout(buttonsLayout);
}
