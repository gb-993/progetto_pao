#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "single_sensor_layout.h"
#include "sensors_list_layout.h"
#include "top_layout.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *bottomLayout;
    TopLayout* top;
    SensorsListLayout* sensors_list;
    SingleSensorLayout* single_sensor;
    QWidget* centralWidget;
public:
    MainWindow(TopLayout*, SensorsListLayout*, SingleSensorLayout*, QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
