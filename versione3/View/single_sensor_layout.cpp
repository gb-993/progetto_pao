#include "single_sensor_layout.h"

SingleSensorLayout::SingleSensorLayout(SensorOptions* so, InfoLayout* in, ChartsLayout* ch, QWidget* parent):
    option(so), info(in), chart(ch), QWidget(parent) {
    // Setto caratteristiche SensorsListLayout
    containerWidget = new QWidget();
    mainLayout = new QVBoxLayout();
    sensorLabel = new QLabel("Select a single sensor");
    rightLayout = new QVBoxLayout();
    layout = new QHBoxLayout();
    containerWidget->setStyleSheet("background-color: #c2c2a3;");

    // Setto caratteristiche etichetta
    sensorLabel->setStyleSheet("color: #000080; font-size: 18px;"); // Imposta il colore del testo su verde e la dimensione del carattere a 16px
    sensorLabel->setAlignment(Qt::AlignCenter); // Allinea il testo al centro

    // Aggiungo etichetta al layout
    layout->addWidget(sensorLabel);

    layout->addWidget(option);
    rightLayout->addWidget(info);
    rightLayout->addWidget(chart);
    option->hide();
    chart->hide();
    //setUpOptions();
    layout->addLayout(rightLayout);
    //setLayout(layout);

    // Impostare il layout del widget contenitore
    containerWidget->setLayout(layout);

    // Impostare il layout principale del SingleSensorLayout
    mainLayout->addWidget(containerWidget);

    setLayout(mainLayout);
}

void SingleSensorLayout::setUpOptions(Sensor* s) {
    // Nascondo l'elemento label
    sensorLabel->hide(); // TROVARE IL MODO DI VISUALIZZARLA QUANDO NON HO PIù SENSOR NELLA PARTE A SINISTRA

    // Aggiungo elementi al layout
    option->show();
    option->setUpOptions(s);
    info->setUpInfo(s);
    info->show();
    chart->setUpChart(s);
    chart->show();


    // Imposto il layout --> DECOMMENTO DOPO QUANDO NON LA CHIAMO ALL'INTERNO DEL COSTRUTTORE
    setLayout(layout);
}

