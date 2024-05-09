#ifndef SENSOR_OPTIONS_H
#define SENSOR_OPTIONS_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class SensorOptions: public QWidget{
private:
    QVBoxLayout* buttonsLayout;
    QPushButton* modify;
    QPushButton* deleteButton;
    QPushButton* start_simulation;
public:
    SensorOptions();
};

#endif // SENSOR_OPTIONS_H
