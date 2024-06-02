#include "info_layout.h"

InfoLayout::InfoLayout(QWidget* parent): QWidget(parent) {
    setFixedHeight(150);

    label1 = new QLabel();
    label2 = new QLabel();
    label3 = new QLabel();
    riga1 = new QHBoxLayout();
    riga2 = new QHBoxLayout();
    layout = new QVBoxLayout();
    visitor = new SensorInfoVisitor();

    riga1->addWidget(label1);
    riga2->addWidget(label2);

    layout->addLayout(riga1);
    layout->addLayout(riga2);

    setLayout(layout);
}

void InfoLayout::setUpInfo(Sensor* s){

    label1->setText(QString("<b>Id:</b> %1 <b>Name:</b> %2").arg(s->getInfo().at(0), s->getInfo().at(1)));
    label1->setStyleSheet("color: #000080;");
    label2->setText(QString("<b>Type:</b> %1 <b>Environment:</b> %2").arg(s->getInfo().at(2), s->getInfo().at(3)));
    label2->setStyleSheet("color: #000080;");

    s->accept(*visitor);
    if(label3){
        delete label3;
    }
    label3 = visitor->getLabel();
    layout->addWidget(label3);

    // TROVARE MODO PER NON FARLO AGGIUNGERE OGNI VOLTA CHE VIENE CHIAMATA SETUPINFO
    s->addObserver(this);
}

void InfoLayout::notify(Sensor& s) {
    label1->setText(QString("<b>Id:</b> %1 <b>Name:</b> %2").arg(s.getInfo().at(0), s.getInfo().at(1)));
    label2->setText(QString("<b>Type:</b> %1 <b>Environment:</b> %2").arg(s.getInfo().at(2), s.getInfo().at(3)));
    s.accept(*visitor);
    if(label3){
        delete label3;
    }
    label3 = visitor->getLabel();
    layout->addWidget(label3);
}
