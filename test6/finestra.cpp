#include "finestra.h"

Finestra::Finestra(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Nuova Finestra");
    resize(300, 200);

    //QWidget *centralWidget = new QWidget(this);
    //setCentralWidget(centralWidget);

    //QGridLayout *layout = new QGridLayout(centralWidget);

    s = new Sensor;
    s->addObserver(this);

    yellowLabel = new QLabel(s->getName(), this);
    yellowLabel->setStyleSheet("background-color: yellow");

    //this->addWidget(yellowLabel, 0, 0, 1, 1, Qt::AlignTop | Qt::AlignHCenter);

    QPushButton* button = new QPushButton(this);
    connect(button, &QPushButton::clicked, this, &Finestra::cambiaNome);

}

void Finestra::cambiaNome() {
    s->setName("Prova2");
}

void Finestra::notify(Sensor& sensor) {
    //qDebug() << "Nome cambiato: " <<  sensor.getName();
    yellowLabel->setText ("Se vedo questo il polimorfismo funziona: " + sensor.getName());
}
