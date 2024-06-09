#ifndef SENSOR_OPTIONS_H
#define SENSOR_OPTIONS_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "../Model/sensor_visitor_interface.h"
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"
#include "charts_layout.h"
#include "custom_button.h"

class SensorOptions: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* buttonsLayout;
    QPushButton* modify;
    QPushButton* deleteButton;
    CustomButton* start_simulation;
private slots:
    void showModifyWindow();
    void showDeleteWindow();
    void startNewSimulation(QPointer<Sensor>);
signals:
    void showModifyWindowSignal();
    void showDeleteWindowSignal();
    void startNewSimulationSignal(Sensor*);
public:
    SensorOptions(QWidget* parent = nullptr);
    void setUpButtonOptions(Sensor*);
};

#endif // SENSOR_OPTIONS_H
