#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), general_window(new GeneralWindow()) {
    /*
    QWidget *centralWidget1 = new QWidget(this);
    setCentralWidget(centralWidget1);

    QGridLayout *layout = new QGridLayout(centralWidget1);

    s = new Sensor;
    s->addObserver(this);

    yellowLabel = new QLabel(s->getName(), this);
    yellowLabel->setStyleSheet("background-color: yellow");

    layout->addWidget(yellowLabel, 0, 0, 1, 1, Qt::AlignTop | Qt::AlignHCenter);

    QPushButton* button = new QPushButton(this);
    connect(button, &QPushButton::clicked, this, &MainWindow::cambiaNome);

    Finestra *finestra = new Finestra(this);
    finestra->setFixedSize(800, 600);
    finestra->show();
    */
    /*
    // Creazione dei widget per le parti colorate
    QWidget *topWidget = new QWidget();
    topWidget->setStyleSheet("background-color: green;");
    topWidget->setFixedHeight(50); // Altezza verde

    QWidget *sensorsWidget = new QWidget();
    sensorsWidget->setStyleSheet("background-color: yellow;");
    sensorsWidget->setFixedWidth(200); // Larghezza giallo

    QWidget *single_sensor_Widget = new QWidget();
    single_sensor_Widget->setStyleSheet("background-color: red;");

    QWidget *sensor_options_Widget = new QWidget();
    sensor_options_Widget->setStyleSheet("background-color: purple;");
    sensor_options_Widget->setFixedWidth(150); // Larghezza viola

    QWidget *info_charts_Widget = new QWidget();
    info_charts_Widget->setStyleSheet("background-color: blue;");

    QWidget *infoWidget = new QWidget();
    infoWidget->setStyleSheet("background-color: brown;");
    infoWidget->setFixedHeight(70); // Altezza marrone

    QWidget *chartWidget = new QWidget();
    chartWidget->setStyleSheet("background-color: white;");

    // Layout per la parte verde sopra
    QVBoxLayout *topLayout = new QVBoxLayout();
    topLayout->addWidget(topWidget);

    // Layout per la parte viola e blu dentro la parte gialla
    QHBoxLayout *single_sensor_Layout = new QHBoxLayout();
    single_sensor_Layout->addWidget(sensor_options_Widget);
    single_sensor_Layout->addWidget(info_charts_Widget);

    // Widget secondario che conterrà il single_sensor_Layout
    //QWidget *secondWidget = new QWidget();
    single_sensor_Widget->setLayout(single_sensor_Layout);

    // Layout verticale per info e charts (marrone e bianco) dentro la parte blu
    QVBoxLayout *info_charts_Layout = new QVBoxLayout();
    info_charts_Layout->addWidget(infoWidget);
    info_charts_Layout->addWidget(chartWidget);

    // Widget secondario che conterrà il info_charts_Layout
    //QWidget *secondWidget = new QWidget();
    info_charts_Widget->setLayout(info_charts_Layout);

    // Layout per la parte gialla a sinistra e rossa a destra
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(sensorsWidget);
    bottomLayout->addWidget(single_sensor_Widget);

    QWidget *bottomWidget = new QWidget();
    bottomWidget->setLayout(bottomLayout);

    // Layout principale per la finestra
    QVBoxLayout *windowLayout = new QVBoxLayout();
    windowLayout->addLayout(topLayout);
    windowLayout->addWidget(bottomWidget);

    // Imposta il layout principale sulla finestra
    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(windowLayout);
    setCentralWidget(centralWidget);
    */

    //GeneralWindow* general_window = new GeneralWindow();
    setCentralWidget(general_window);
}

MainWindow::~MainWindow() {}

void MainWindow::cambiaNome() {
    s->setName("Prova");
}

void MainWindow::notify(Sensor& sensor) {
    //qDebug() << "Nome cambiato: " <<  sensor.getName();
    yellowLabel->setText ("Name: " + sensor.getName());
}
