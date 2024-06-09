#include "single_sensor_layout.h"
#include "sensor_options.h"

SingleSensorLayout::SingleSensorLayout(SensorOptions* so, InfoLayout* in, ChartsLayout* ch, QWidget* parent):
    QWidget(parent),
    option(so), info(in), chart(ch) {
    containerWidget = new QWidget();
    mainLayout = new QVBoxLayout();
    sensorLabel = new QLabel("Select a single sensor");
    rightLayout = new QVBoxLayout();
    layout = new QHBoxLayout();
    containerWidget->setStyleSheet("background-color: #c2c2a3;");

    sensorLabel->setStyleSheet("color: #000080; font-size: 18px;");
    sensorLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(sensorLabel);

    layout->addWidget(option);
    rightLayout->addWidget(info);
    rightLayout->addWidget(chart);
    option->hide();
    chart->hide();
    layout->addLayout(rightLayout);

    containerWidget->setLayout(layout);

    mainLayout->addWidget(containerWidget);

    setLayout(mainLayout);
}

void SingleSensorLayout::setUpOptions(Sensor* s) {
    sensorLabel->hide();

    option->setUpButtonOptions(s);
    option->show();

    info->setUpInfo(s);
    info->show();

    if(!s->has_simulation_data()){
        s->genSimulation();
    }
    chart->setUpChart(s->getSimData());
    chart->show();
}

QLabel* SingleSensorLayout::getLabel() const {
    return sensorLabel;
}

