#include "charts_layout.h"

//QT_CHARTS_USE_NAMESPACE // Per semplificare l'utilizzo dei namespace

ChartsLayout::ChartsLayout(): layout(new QVBoxLayout()), series(new QLineSeries()), chart(new QChart()),
    axisX(new QValueAxis()), axisY(new QValueAxis()), chartView(new QChartView(chart)) {}

void ChartsLayout::setUpChart(Sensor* s) {

    if(series){
        series->clear();
    }

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

    if(chart){
        chart->removeAxis(axisX);
        chart->removeAxis(axisY);
    }

    chart->createDefaultAxes(); // Questo adatta gli assi automaticamente

    chart->legend()->setVisible(false); // Imposta la visibilità della legenda

    // Creazione della vista del grafico
    chartView->setRenderHint(QPainter::Antialiasing); // serve per ridurre gli effetti di bordo irregolari e migliorare l'aspetto visivo dei disegni

    layout->addWidget(chartView);

    setLayout(layout);
}
