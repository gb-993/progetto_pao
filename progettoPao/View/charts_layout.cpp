#include "charts_layout.h"

ChartsLayout::ChartsLayout(QWidget* parent): QWidget(parent) {
    layout = new QVBoxLayout();
    chart = new QChart();
    chartView = new QChartView(chart);
    visitor = new SensorChartVisitor(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);
    setLayout(layout);
}

// setUp del grafico
void ChartsLayout::setUpChart(Sensor *s) {
    for (QAbstractSeries *series : chart->series()) {
        chart->removeSeries(series);
    }
    s->accept(*visitor);
}

