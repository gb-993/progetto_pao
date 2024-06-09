#include "mainwindow.h"

MainWindow::MainWindow(TopLayout* t, SensorsListLayout* sl, SingleSensorLayout* ss, QWidget *parent):  QMainWindow(parent), top(t), sensors_list(sl), single_sensor(ss) {
    this->setWindowTitle("Winery control system");

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    mainLayout = new QVBoxLayout(centralWidget);

    bottomLayout = new QHBoxLayout();

    mainLayout->addWidget(top);

    bottomLayout->addWidget(sensors_list);
    bottomLayout->addWidget(single_sensor);

    mainLayout->addLayout(bottomLayout);

}



MainWindow::~MainWindow() {}

