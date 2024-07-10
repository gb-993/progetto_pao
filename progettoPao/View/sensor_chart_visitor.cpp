#include "sensor_chart_visitor.h"

SensorChartVisitor::SensorChartVisitor(QChart*c): chart(c) {}

// ritorna la label
QChart* SensorChartVisitor::getChart() const{
    return chart;
}

// override dei metodi virtuali puri del visitor

void SensorChartVisitor::visitLight(Sensor_light& light) {
    QList<QPointF> data = light.getSimData(); // Retrieve the simulation data
    QBarSeries *series = new QBarSeries();

    QBarSet *barSet = new QBarSet("");
    QStringList categories;

    // Assuming each point in data represents a different bar
    for (const QPointF &point : data) {
        *barSet << point.y();
        categories << QString::number(point.x());
    }

    series->append(barSet);

    // Remove existing series and add the new one
    for (QAbstractSeries *existingSeries : chart->series()) {
        chart->removeSeries(existingSeries);
    }
    chart->addSeries(series);

    chart->createDefaultAxes(); // Adjust axes as needed

    // Add axis titles
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%.2f");
    chart->addAxis(axisY, Qt::AlignLeft);

    chart->legend()->setVisible(true); // Adjust legend visibility as needed
    chart->legend()->setAlignment(Qt::AlignBottom); // Position legend at the bottom
}

void SensorChartVisitor::visitTemperature(Sensor_temperature& temp) {

    QList<QPointF> dati = temp.getSimData();
    QLineSeries *series = new QLineSeries();
    if (chart->series().contains(series)) {
        chart->removeSeries(series);
    }
    series->clear();

    for (const QPointF &punto : dati) {
        series->append(punto);
    }

    QPen pen(Qt::darkBlue);
    series->setPen(pen);

    chart->addSeries(series);

    chart->setTitle("Simulation");

    chart->createDefaultAxes();

    chart->legend()->setVisible(false);
}

void SensorChartVisitor::visitHumidity(Sensor_humidity& hum) {

    QList<QPointF> dati = hum.getSimData();
    QLineSeries *series = new QLineSeries();
    if (chart->series().contains(series)) {
        chart->removeSeries(series);
    }
    series->clear();

    for (const QPointF &punto : dati) {
        series->append(punto);
    }

    QPen pen(Qt::darkBlue);
    series->setPen(pen);

    chart->addSeries(series);

    chart->setTitle("Simulation");

    chart->createDefaultAxes();

    chart->legend()->setVisible(false);
}

void SensorChartVisitor::visitVolume(Sensor_volume& vol) {

    QList<QPointF> data = vol.getSimData();
    QBarSeries *series = new QBarSeries();

    QBarSet *barSet = new QBarSet("");
    QStringList categories;

    // Assuming each point in data represents a different bar
    for (const QPointF &point : data) {
        *barSet << point.y();
        categories << QString::number(point.x());
    }

    series->append(barSet);

    // Remove existing series and add the new one
    for (QAbstractSeries *existingSeries : chart->series()) {
        chart->removeSeries(existingSeries);
    }
    chart->addSeries(series);

    chart->createDefaultAxes();

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%.2f");
    chart->addAxis(axisY, Qt::AlignLeft);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
}
void SensorChartVisitor::visitFilter(Sensor_filter& filter) {

    QList<QPointF> dati = filter.getSimData();
    QLineSeries *series = new QLineSeries();
    if (chart->series().contains(series)) {
        chart->removeSeries(series);
    }
    series->clear();

    for (const QPointF &punto : dati) {
        series->append(punto);
    }

    QPen pen(Qt::darkBlue);
    series->setPen(pen);

    chart->addSeries(series);

    chart->setTitle("Simulation");

    chart->createDefaultAxes();

    chart->legend()->setVisible(false);
}
