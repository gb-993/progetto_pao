#ifndef INFO_LAYOUT_H
#define INFO_LAYOUT_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "sensor_light.h"
#include "sensor_filter.h"
#include "sensor_humidity.h"
#include "sensor_temperature.h"
#include "sensor_volume.h"
#include "sensor_info_visitor.h"

class InfoLayout: public QWidget {
    Q_OBJECT
private:
    QLabel* label1;
    QLabel* label2;
    QHBoxLayout* riga1;
    QHBoxLayout* riga2;
    QVBoxLayout* layout;
    SensorInfoVisitor* visitor;
public:
    InfoLayout();
};

#endif // INFO_LAYOUT_H
