#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "sensor.h"
#include "sensor_observer_interface.h"
#include "finestra.h"
#include "general_window.h"


class MainWindow : public QMainWindow, public Sensor_observer_interface {
    Q_OBJECT
private:
    GeneralWindow* general_window;
    Sensor* s;
    QLabel* yellowLabel;
    //QPushButton *button;
    //Info* infoWidget;
public:
    MainWindow(QWidget *parent = nullptr);
    void cambiaNome();
    virtual void notify(Sensor&);
    ~MainWindow();
};
#endif // MAINWINDOW_H
