#include "info_layout.h"

InfoLayout::InfoLayout(): label1(new QLabel()), label2(new QLabel()), riga1(new QHBoxLayout()),
    riga2(new QHBoxLayout()), layout(new QVBoxLayout()), visitor(new SensorInfoVisitor()) {
    setStyleSheet("background-color: brown; color: white");
    setFixedHeight(150);

    //ora creo un sensore qua, ma in realtà vorrei che mi venga passato come campo del costruttore (dato che sono le info di un singolo sensore)
    // probabilmente da un SensorManager
    Sensor* s = new Sensor_light();

    label1->setText(QString("<b>Id:</b> %1 <b>Name:</b> %2").arg(s->getInfo().at(0), s->getInfo().at(1)));
    label2->setText(QString("<b>Type:</b> %1 <b>Environment:</b> %2").arg(s->getInfo().at(2), s->getInfo().at(3)));

    s->accept(*visitor);

    riga1->addWidget(label1);
    riga2->addWidget(label2);

    layout->addLayout(riga1);
    layout->addLayout(riga2);
    layout->addWidget(visitor->getWidget());

    setLayout(layout);
}
