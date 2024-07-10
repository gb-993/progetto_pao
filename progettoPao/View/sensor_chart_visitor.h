#ifndef SENSOR_CHART_VISITOR_H
#define SENSOR_CHART_VISITOR_H

#include <QWidget>
#include <QLabel>
#include <QChart>
#include <QLineSeries>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QBarSet>
#include <QValueAxis>

#include "../Model/sensor_visitor_interface.h"
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

class SensorChartVisitor: public SensorVisitorInterface {
private:
    QChart* chart;
public:
    SensorChartVisitor(QChart*);
    QChart* getChart() const;
    void visitLight(Sensor_light&);
    void visitTemperature(Sensor_temperature&);
    void visitHumidity(Sensor_humidity&);
    void visitVolume(Sensor_volume&);
    void visitFilter(Sensor_filter&);
};

#endif // SENSOR_CHART_VISITOR_H
