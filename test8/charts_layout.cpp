#include "charts_layout.h"

//QT_CHARTS_USE_NAMESPACE // Per semplificare l'utilizzo dei namespace

ChartsLayout::ChartsLayout(): layout(new QVBoxLayout()), series(new QLineSeries()), chart(new QChart()),
    axisX(new QValueAxis()), axisY(new QValueAxis()), chartView(new QChartView(chart)) {
    setStyleSheet("background-color: black;");

    // intanto creo sensore qua
    Sensor* s = new Sensor_temperature();
    s->genSimulation();
    QList<QPointF> dati = s->getSimData();

    for (const QPointF &punto : dati) {
        series->append(punto);
    }

    // Aggiungi la serie al grafico
    chart->addSeries(series);

    chart->setTitle("Simulazione");

    chart->createDefaultAxes(); // Questo adatta gli assi automaticamente

    chart->legend()->setVisible(false); // Imposta la visibilità della legenda

    // Creazione della vista del grafico
    chartView->setRenderHint(QPainter::Antialiasing); // serve per ridurre gli effetti di bordo irregolari e migliorare l'aspetto visivo dei disegni

    layout->addWidget(chartView);

    setLayout(layout);
}
