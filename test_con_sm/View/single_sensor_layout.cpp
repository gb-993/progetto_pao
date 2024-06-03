#include "single_sensor_layout.h"

SingleSensorLayout::SingleSensorLayout( SensorOptions* op, InfoLayout* in, ChartsLayout* ch, QWidget* parent):
    option(op), info(in), chart(ch), QWidget(parent) {

    // Setto caratteristiche SensorsListLayout
    containerWidget = new QWidget();
    containerWidget->setStyleSheet("background-color: #c2c2a3;");

    mainLayout = new QVBoxLayout();
    sensorLabel = new QLabel("Select a single sensor");
    // Setto caratteristiche etichetta
    sensorLabel->setStyleSheet("color: #000080; font-size: 18px;"); // Imposta il colore del testo su verde e la dimensione del carattere a 16px
    sensorLabel->setAlignment(Qt::AlignCenter); // Allinea il testo al centro

    rightLayout = new QVBoxLayout();
    layout = new QHBoxLayout();

    // riempio i layout CON COSA?  -> con le cose che ha costruito nel costruttore di QUESTA classe
    // invece deve aggiungere quelli costruiti dal CONTROLLER ( a parte sensorLabel, sfigata)
    rightLayout->addWidget(info);
    rightLayout->addWidget(chart);
    layout->addWidget(sensorLabel);
    layout->addWidget(option);
    layout->addLayout(rightLayout);

    // click su myPushButton: 1) hide() delle info precedenti ( se presenti)
    //                        2) modifica delle cose
    //                        3) show() con le info aggiornate
    // non devono più vedersi se il sensore di riferimento viene eliminato
    option->hide();
    chart->hide();
    option->hide();



    // Impostare il layout del widget contenitore
    containerWidget->setLayout(layout);
    // Impostare il layout intermedio del SingleSensorLayout
    mainLayout->addWidget(containerWidget);
    // Impostare il layout principale del SingleSensorLayout
    setLayout(mainLayout);
}

void SingleSensorLayout::setUpOptions(Sensor* s) {
    // Nascondo l'elemento label
    sensorLabel->hide(); // TROVARE IL MODO DI VISUALIZZARLA QUANDO NON HO PIù SENSOR NELLA PARTE A SINISTRA

    // Aggiungo elementi al layout
    //option->setUpButtonOptions(s);
    option->show();

    info->setUpInfo(s);
    info->show();

    if(!s->has_simulation_data()){
        s->genSimulation();
    }
    chart->setUpChart(s->getSimData());
    chart->show();


    // Imposto il layout --> DECOMMENTO DOPO QUANDO NON LA CHIAMO ALL'INTERNO DEL COSTRUTTORE
    setLayout(layout);
}

