#include "general_window.h"

GeneralWindow::GeneralWindow(): mainLayout(new QVBoxLayout()), bottomLayout(new QHBoxLayout()), top(new TopLayout()), sensors_list(new SensorsListLayout), single_sensor(new SingleSensorLayout()) {

    mainLayout->addWidget(top);

    bottomLayout->addWidget(sensors_list);
    bottomLayout->addWidget(single_sensor);

    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);
}
