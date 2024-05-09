#include "info_layout.h"

InfoLayout::InfoLayout(): label1(new QLabel()), label2(new QLabel()), label3(new QLabel()), riga1(new QHBoxLayout()), riga2(new QHBoxLayout()), riga3(new QHBoxLayout()), layout(new QVBoxLayout()) {
    setStyleSheet("background-color: brown; color: white");
    setFixedHeight(150);

    //ora creo un sensore qua, ma in realtà vorrei che mi venga passato come campo del costruttore (dato che sono le info di un singolo sensore)
    // probabilmente da un SensorManager
    Sensor* s = new Sensor();

    //label1->setText (QString("<b>Id:</b> %1 <b>Name:</b> %2 <b>Type:</b> %3").arg(s->getId()).arg(s->getName()).arg(s->getType()));
    label1->setText (QString("<b>Id:</b> %1 <b>Name:</b> %2 <b>Type:</b> %3").arg(QString::number(s->getId()), s->getName(), s->getType()));
    label2->setText (QString("<b>Upper Value:</b> %1 <b>Lower Value:</b> %2").arg(QString::number(s->getUpper()), QString::number(s->getLower())));
    label3->setText (QString("<b>Environment:</b> %1 <b>Measure Unit:</b> %2").arg(s->getEnv(), s->getMU()));

    /*
    label1->setText ("Id: " + QString::number(s->getId()) + "Name: " + s->getName() + "Type: " + s->getType());
    label2->setText ("Upper Value: " + QString::number(s->getUpper()) + "Lower Value: " + QString::number(s->getLower()));
    label3->setText ("Environment: " + s->getEnv() + "Measure Unit: " + s->getMU());
    */

    label1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    riga1->addWidget(label1);
    riga2->addWidget(label2);
    riga3->addWidget(label3);

    layout->addLayout(riga1);
    layout->addLayout(riga2);
    layout->addLayout(riga3);

    setLayout(layout);
}
