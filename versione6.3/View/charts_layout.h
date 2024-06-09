#ifndef CHARTS_LAYOUT_H
#define CHARTS_LAYOUT_H

#include <QChart>
#include <QWidget>
#include <QLineSeries>
#include <QValueAxis>
#include <QChartView>
#include <QPointF>
#include <QVBoxLayout>

class ChartsLayout: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QLineSeries *series;
    QChart *chart;
    QChartView *chartView;
public:
    ChartsLayout(QWidget* parent = nullptr);
    void setUpChart(QList<QPointF>);
};

#endif // CHARTS_LAYOUT_H
