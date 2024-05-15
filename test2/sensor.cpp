#include "sensor.h"

Sensor::Sensor(QString n, QString t, QString e): id(generateId()), name(n), type(t), environment(e), simulationData() {}

int Sensor::counter = 0; // Variabile statica per tenere traccia del contatore
int Sensor::generateId() const {
    return ++counter;
}

// metodi get
int Sensor::getId() const {
    return id;
}
QString Sensor::getName() const {
    return name;
}
QString Sensor::getType() const {
    return type;
}
QString Sensor::getEnv() const {
    return environment;
}
QList<QPointF> Sensor::getSimData() const {
    return simulationData;
}

// metodi set
void Sensor::setName(const QString& n) {
    name = n;
}
void Sensor::setType(const QString& t) {
    type = t;
}
void Sensor::setEnv(const QString& e) {
    environment = e;
}
// ATTENZIONE: quando faccio il controller metto dentro la funzione avvia_simulazione tutta la parte di generazione dei punto e
// lascio dentro questo metodo solo la parte che riguarda simulationData a cui la funzione avvia_simulazione non avrebbe accesso
/*void Sensor::setSimulation() {
    //pulisce la lista della simulazione precedente
    simulationData.clear();

    //genera punti causali
    QRandomGenerator generator;
    int x = 0;
    int y = 0;
    for(int i = 0; i < 50; i ++) {
        x += 1;
        y = generator.bounded(lower,upper);
        simulationData.append(QPointF(x, y)); // aggiunge il punto alla lista
    }
}*/
void Sensor::setSimulationData(const QList<QPointF>& p){
    simulationData.append(p);
}

bool Sensor::has_simulation_data() const {
    if(simulationData.empty()) return false;
    return true;
}


void Sensor::print_sensor() const {
    qDebug()<<getId()<<getName()<<getType()<<getEnv();
    if(has_simulation_data()){
        qDebug() << "Lista di punti: ";
        for (const QPointF &point : getSimData()) {
            qDebug() << "(" << point.x() << "," << point.y() << ")";
        }
    }
}

