#ifndef SENSOR_OPTIONS_H
#define SENSOR_OPTIONS_H

#include <QWidget>
#include <QVBoxLayout>
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
