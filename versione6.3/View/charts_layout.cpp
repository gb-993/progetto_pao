#include "charts_layout.h"

ChartsLayout::ChartsLayout(QWidget* parent): QWidget(parent) {
    layout = new QVBoxLayout();
    series = new QLineSeries();
    chart = new QChart();
    chartView = new QChartView(chart);

    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);
    setLayout(layout);
}

void ChartsLayout::setUpChart(QList<QPointF> dati) {
    if (chart->series().contains(series)) {
        chart->removeSeries(series);
    }
    series->clear();

    for (const QPointF &punto : dati) {
        series->append(punto);
    }

    QPen pen(Qt::darkBlue);
    series->setPen(pen);

    // Aggiungi la serie al grafico
    chart->addSeries(series);

    chart->setTitle("Simulation");

    chart->createDefaultAxes(); // Questo adatta gli assi automaticamente

    chart->legend()->setVisible(false); // Imposta la visibilità della legenda

}

