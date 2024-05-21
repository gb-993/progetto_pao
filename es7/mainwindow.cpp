#include "mainwindow.h"
#include <QpointF>
#include <QList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // creo pushbutton
    button1 = new QPushButton("Button 1", this);
    button2 = new QPushButton("Button 2", this);
    button3 = new QPushButton("Button 3", this);

    // creo layout e ci aggiungo i widget che contengono i pushbutton
    QVBoxLayout *layoutButton = new QVBoxLayout();
    layoutButton->addWidget(button1);
    layoutButton->addWidget(button2);
    layoutButton->addWidget(button3);



    // creo i punti e li aggiungo alla lista
    QLineSeries *series = new QLineSeries();
    int x = 0;
    int y = 0;
    //QPointF p;
    for(int i = 0; i < 5; i ++) {
        x += 1;
        y += 2;
        series->append(QPointF(x, y)); // aggiunge il punto alla lista
                                       // ma è una QLineSeries
                                       // e noi abbiamo una QList<QPointF>
        // simulationData.append(QPointF(x,y));      -> non viene accettata da addSeries di chart
    }

    // creo un chart e lo inizializzo
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");
    chart->addSeries(series);    // aggiunge dati al grafico, non gli va bene una QList<QPoinF>

    // creo "lo spazio" per ospitare il chart (credo sia necessario)
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // creo la Window e il suo layout generale
    window = new QWidget();
    QHBoxLayout *layoutGenerale = new QHBoxLayout(window);

    // aggiungo al layout generale sia il layout dei pushbutton, che "lo spazio" che contiene il chart
    layoutGenerale->addLayout(layoutButton);
    layoutGenerale->addWidget(chartView);

    // setta la finestra aggiungendoci il layout generale
    window->setLayout(layoutGenerale);
    window->resize(400, 300);
    window->show();


}


MainWindow::~MainWindow() {}









