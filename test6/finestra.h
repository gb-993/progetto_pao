#ifndef FINESTRA_H
#define FINESTRA_H

#include <QDialog>
#include <QMainWindow>
#include <QGridLayout>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include "sensor.h"
#include "sensor_observer_interface.h"

class Finestra : public QDialog, public Sensor_observer_interface {
    Q_OBJECT

private:
    Sensor* s;
    QLabel* yellowLabel;
public:
    Finestra(QWidget *parent = nullptr);
    void cambiaNome();
    virtual void notify(Sensor&);
};

#endif // FINESTRA_H
