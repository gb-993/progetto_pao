#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QGridLayout *layout = new QGridLayout(centralWidget);

    s = new Sensor;
    s->addObserver(this);

    yellowLabel = new QLabel(s->getName(), this);
    yellowLabel->setStyleSheet("background-color: yellow");

    layout->addWidget(yellowLabel, 0, 0, 1, 1, Qt::AlignTop | Qt::AlignHCenter);

    QPushButton* button = new QPushButton(this);
    connect(button, &QPushButton::clicked, this, &MainWindow::cambiaNome);

    Finestra *finestra = new Finestra(this);
    finestra->show();
}

MainWindow::~MainWindow() {}

void MainWindow::cambiaNome() {
    s->setName("Prova");
}

void MainWindow::notify(Sensor& sensor) {
    //qDebug() << "Nome cambiato: " <<  sensor.getName();
    yellowLabel->setText ("Name: " + sensor.getName());
}
