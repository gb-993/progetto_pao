#include "sensor.h"

Sensor::Sensor(QString n, QString t, QString e, QObject* parent): QObject(parent), id(generateId()), name(n), type(t), environment(e),  simulationData() {}

// genera id univoco
int Sensor::counter = 0;
int Sensor::generateId() const {
    return counter++;
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
QList<QString> Sensor::getInfo() const{
    QList<QString> list;
    list.append(QString::number(getId()));
    list.append(getName());
    list.append(getType());
    list.append(getEnv());
    return list;
}

// metodi set e chiamata alla lista di osservatori

void Sensor::setName(const QString& n) {
    name = n;
    notifyObservers(*this);
}
void Sensor::setType(const QString& t) {
    type = t;
    notifyObservers(*this);
}
void Sensor::setEnv(const QString& e) {
    environment = e;
    notifyObservers(*this);
}
void Sensor::setSimulationData(const QList<QPointF>& p){
    simulationData.append(p);
    notifyObservers(*this);
}

// controlla la presenza di dati di simulazione
bool Sensor::has_simulation_data() const {
    if(simulationData.empty()) return false;
    return true;
}

// aggiunge un osservatore alla lista di osservatori
void Sensor::addObserver(Sensor_observer_interface *obs) {
    if (obs == nullptr) return;
    if (std::find(observers.begin(), observers.end(), obs) != observers.end()) return;
    observers.push_back(obs);
}

// notifica ogni osservatore presente nella lista degli osservatori
void Sensor::notifyObservers(Sensor& s) {
    for(auto obs=observers.begin(); obs!=observers.end(); obs++){
        (*obs)->notify(s);
    }
}

// salva i campi in comune del sensore astratto per la conversione in formato json
QJsonObject Sensor::sensorToJsonCommonField() const {
    QJsonObject sensorObject;
    sensorObject["id"] = getId();
    sensorObject["name"] = getName();
    sensorObject["type"] = getType();
    sensorObject["environment"] = getEnv();
    return sensorObject;
}

