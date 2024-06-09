#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include "general_window.h"
#include "modify_sensor_window.h"
#include "confirm_delete_window.h"
#include "create_sensor_window.h"
#include "single_sensor_layout.h"

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
    GeneralWindow* getWindow();
    ~MainWindow();
};
#endif // MAINWINDOW_H
