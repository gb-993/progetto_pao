#ifndef INFO_LAYOUT_H
#define INFO_LAYOUT_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"
#include "sensor_info_visitor.h"

class InfoLayout: public QWidget, public Sensor_observer_interface {
    Q_OBJECT
private:
    QLabel* label1;
    QLabel* label2;
    QLabel* label3;
    QHBoxLayout* riga1;
    QHBoxLayout* riga2;
    QVBoxLayout* layout;
    SensorInfoVisitor* visitor;
public:
    InfoLayout(QWidget* parent = nullptr);
    void setUpInfo(Sensor*);
    virtual void notify(Sensor&);
};

#endif // INFO_LAYOUT_H
