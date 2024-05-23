#ifndef SINGLE_SENSOR_LAYOUT_H
#define SINGLE_SENSOR_LAYOUT_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "sensor_options.h"
#include "info_layout.h"
#include "charts_layout.h"

class SingleSensorLayout: public QWidget{
    Q_OBJECT
private:
    QWidget* containerWidget;
    QVBoxLayout* mainLayout;
    QLabel *sensorLabel;
    QHBoxLayout *layout;
    SensorOptions* option;
    QVBoxLayout *rightLayout;
    InfoLayout* info;
    ChartsLayout* chart;
public:
    SingleSensorLayout();
    void setUpOptions(); // DA METTERE NEL CONTROLLER???? booohhhhhh oppure il controller chiama questa funzione
    // quando seleziono un singolo sensore?
    // probabilmente si altrimenti non ho accesso ai campi privati
};

#endif // SINGLE_SENSOR_LAYOUT_H
