#ifndef INFO_H
#define INFO_H

#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QVBoxLayout>
#include "sensor_observer_interface.h"
#include "sensor.h"

class Info: public QWidget, public Sensor_observer_interface {
   Q_OBJECT
private:
    Sensor& sensor;
    QLabel* name_label;

public:
    Info(Sensor& sensor, QWidget* parent=0);
    void show();
    virtual void notify (Sensor&);
};

#endif // INFO_H
