#include "single_sensor_layout.h"

SingleSensorLayout::SingleSensorLayout(): sensorLabel(new QLabel("Select a single sensor")), layout(new QHBoxLayout()), option(new SensorOptions()), rightLayout(new QVBoxLayout()), info(new InfoLayout()), chart(new ChartsLayout()) {
    // Setto caratteristiche SensorsListLayout
    setStyleSheet("background-color: red;");

    // Setto caratteristiche etichetta
    sensorLabel->setStyleSheet("color: white; font-size: 18px;"); // Imposta il colore del testo su verde e la dimensione del carattere a 16px
    sensorLabel->setAlignment(Qt::AlignCenter); // Allinea il testo al centro

    // Aggiungo etichetta al layout
    layout->addWidget(sensorLabel);

    setUpOptions();
    layout->addLayout(rightLayout);
    setLayout(layout);
}

void SingleSensorLayout::setUpOptions() {
    // Nascondo l'elemento label
    sensorLabel->hide(); // TROVARE IL MODO DI VISUALIZZARLA QUANDO NON HO PIù SENSOR NELLA PARTE A SINISTRA

    // Aggiungo elementi al layout
    layout->addWidget(option);
    rightLayout->addWidget(info);
    rightLayout->addWidget(chart);

    // Imposto il layout --> DECOMMENTO DOPO QUANDO NON LA CHIAMO ALL'INTERNO DEL COSTRUTTORE
    //setLayout(layout);
}

