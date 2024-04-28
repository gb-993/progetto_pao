// MODEL

#include "sensor.h"

Sensor::Sensor(QString n, QString t, int l, int u): name(n), type(t), simulationData(), lower(l), upper(u) {}

void Sensor::setName(const QString& n) {
    name = n;
}

void Sensor::setType(const QString& t) {
    type = t;
}

// ATTENZIONE: quando faccio il controller metto dentro la funzione avvia_simulazione tutta la parte di generazione dei punto e
// lascio dentro questo metodo solo la parte che riguarda simulationData a cui la funzione avvia_simulazione non avrebbe accesso
void Sensor::setSimulation() { //AGGIUNTA IO: quando premo il tasto avvia simulazione viene chiamata questo metodo
    //pulisce la lista della simulazione precedente
    simulationData.clear();

    //genera punti causali
    QRandomGenerator generator;
    int x = 0;
    int y = 0;
    for(int i = 0; i < 5; i ++) {
        x += 1;
        y = generator.bounded(lower,upper);
        simulationData.append(QPointF(x, y)); // aggiunge il punto alla lista
    }

}

QString Sensor::getName() const {
    return name;
}

QString Sensor::getType() const {
    return type;
}

bool Sensor::has_simulation_data() const{
    if(simulationData.empty()) return false;
    return true;
}

void Sensor::print_sensor() const{
    qDebug()<<getName()<<getType();
    if(has_simulation_data()){
        qDebug() << "Lista di punti: ";
        for (const QPointF &point : simulationData) {
            qDebug() << "(" << point.x() << "," << point.y() << ")";
        }
    }
}
