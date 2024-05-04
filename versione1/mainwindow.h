#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLayout>
#include <QPushButton>
#include "sensor.h"
#include "sensor_observer_interface.h"
#include "finestra.h"

class MainWindow : public QMainWindow, public Sensor_observer_interface
{
    Q_OBJECT
private:
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
