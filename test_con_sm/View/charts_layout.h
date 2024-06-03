#ifndef CHARTS_LAYOUT_H
#define CHARTS_LAYOUT_H

#include <QChart>
#include <QWidget>
#include <QLineSeries>
#include <QValueAxis>
#include <QChartView>
#include <QPointF>
#include <QVBoxLayout>
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

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
    void setUpChart(QList<QPointF>);
};

#endif // CHARTS_LAYOUT_H
