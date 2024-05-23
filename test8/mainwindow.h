#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include "sensor.h"
#include "general_window.h"
#include "modify_sensor_window.h"
#include "confirm_delete_window.h"
#include "create_sensor_window.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    GeneralWindow* general_window;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
