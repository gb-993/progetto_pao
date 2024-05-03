#include "sensor.h"

Sensor::Sensor(QString n, QString t, double l, double u, QString e, QString mu): id(generateId()), name(n), type(t), lower(l), upper(u), environment(e), measure_unit(mu), simulationData() {}

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
double Sensor::getLower() const {
    return lower;
}
double Sensor::getUpper() const {
    return upper;
}
QString Sensor::getEnv() const {
    return environment;
}
QString Sensor::getMU() const {
    return measure_unit;
}
QList<QPointF> Sensor::getSimData() const {
    return simulationData;
}

// metodi set
void Sensor::setName(const QString& n) {
    name = n;
    for(auto obs=observers.begin(); obs!=observers.end(); obs++){
        (*obs)->notify(*this);
    }
}
void Sensor::setType(const QString& t) {
    type = t;
}
void Sensor::setLower(const double& l) {
    lower = l;
}
void Sensor::setUpper(const double& u) {
    upper = u;
}
void Sensor::setEnv(const QString& e) {
    environment = e;
}
void Sensor::setMU(const QString& mu) {
    measure_unit = mu;
}
// ATTENZIONE: quando faccio il controller metto dentro la funzione avvia_simulazione tutta la parte di generazione dei punto e
// lascio dentro questo metodo solo la parte che riguarda simulationData a cui la funzione avvia_simulazione non avrebbe accesso
// DA RIFARE
void Sensor::setSimulation() {
    //pulisce la lista della simulazione precedente
    simulationData.clear();

    //genera punti causali
    QRandomGenerator generator;
    int x = 0;
    int y = 0;
    for(int i = 0; i < 5; i ++) {
        x += 1;
        y += 1;
        simulationData.append(QPointF(x, y)); // aggiunge il punto alla lista
    }
}

bool Sensor::has_simulation_data() const {
    if(simulationData.empty()) return false;
    return true;
}

void Sensor::print_sensor() const {
    qDebug()<<getId()<<getName()<<getType()<<getLower()<<getUpper()<<getEnv();
    if(has_simulation_data()){
        qDebug() << "Lista di punti: ";
        for (const QPointF &point : getSimData()) {
            qDebug() << "(" << point.x() << "," << point.y() << ")";
        }
    }
}

void Sensor::addObserver(Sensor_observer_interface *obs) {
    observers.push_back(obs); // aggiungo osservatore alla lista
}
