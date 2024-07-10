#ifndef CHARTS_LAYOUT_H
#define CHARTS_LAYOUT_H

#include <QChart>
#include <QChartView>
#include <QPointF>
#include <QVBoxLayout>
#include "sensor_chart_visitor.h"

class ChartsLayout: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QChart *chart;
    QChartView *chartView;
    SensorChartVisitor *visitor;
public:
    ChartsLayout(QWidget* parent = nullptr);
    void setUpChart(Sensor*);
    // virtual void notify(Sensor&);
};

#endif // CHARTS_LAYOUT_H
