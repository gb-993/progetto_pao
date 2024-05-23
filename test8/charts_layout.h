#ifndef CHARTS_LAYOUT_H
#define CHARTS_LAYOUT_H

#include <QChart>
#include <QWidget>
#include <QLineSeries>
#include <QValueAxis>
#include <QChartView>
#include <QPointF>
#include <QVBoxLayout>
#include "sensor_light.h"
#include "sensor_filter.h"
#include "sensor_humidity.h"
#include "sensor_temperature.h"
#include "sensor_volume.h"

class ChartsLayout: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QLineSeries *series;
    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QChartView *chartView;
public:
    ChartsLayout();
};

#endif // CHARTS_LAYOUT_H
