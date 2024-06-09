#ifndef SINGLE_SENSOR_LAYOUT_H
#define SINGLE_SENSOR_LAYOUT_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

#include "info_layout.h"
#include "charts_layout.h"
#include "sensor_options.h"

class SingleSensorLayout: public QWidget {
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
    SingleSensorLayout(SensorOptions*, InfoLayout*, ChartsLayout*, QWidget* parent = nullptr);
    void setUpOptions(Sensor*);
    QLabel* getLabel() const;
};

#endif // SINGLE_SENSOR_LAYOUT_H
