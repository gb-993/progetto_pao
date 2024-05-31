#include "charts_layout.h"

ChartsLayout::ChartsLayout(): layout(new QVBoxLayout()), series(new QLineSeries()),
    chart(new QChart()), axisX(new QValueAxis()), axisY(new QValueAxis()), chartView(new QChartView(chart)) {
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);
    setLayout(layout);
}

void ChartsLayout::setUpChart(QList<QPointF> dati) {
    chart->removeSeries(series);
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

/*
void ChartsLayout::setUpChart(Sensor* s) {
    chart->removeSeries(series);
    series->clear();

    s->genSimulation();
    QList<QPointF> dati = s->getSimData();

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
*/
