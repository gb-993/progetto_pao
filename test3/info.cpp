#include <info.h>

Info::Info(Sensor& sensor,QWidget *parent): QWidget(parent), sensor(sensor) {
    QVBoxLayout *layout=new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    name_label=new QLabel();
    layout->addWidget(name_label);
}

void Info::show() {
    name_label->setText(sensor.getName());
}

void Info::notify(Sensor & sensor) {
    name_label->setText ("Name: " + sensor.getName());
}
