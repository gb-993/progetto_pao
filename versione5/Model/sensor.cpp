#include "sensor.h"

Sensor::Sensor(QString n, QString t, QString e): id(generateId()), name(n), type(t), environment(e), simulationData() {}

int Sensor::counter = 0; // Variabile statica per tenere traccia del contatore
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

// metodi set
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

void Sensor::addObserver(Sensor_observer_interface *obs) {
    if (obs == nullptr) return;
    if (std::find(observers.begin(), observers.end(), obs) != observers.end()) return; // se l'osservatore è già presente non lo aggiungo
    observers.push_back(obs); // aggiungo osservatore alla lista
}
void Sensor::notifyObservers(Sensor& s){
    for(auto obs=observers.begin(); obs!=observers.end(); obs++){
        (*obs)->notify(s);
    }
}

QJsonObject Sensor::sensorToJsonCommonField(){
    QJsonObject sensorObject;
    sensorObject["id"] = getId();
    sensorObject["name"] = getName();
    sensorObject["type"] = getType();
    sensorObject["environment"] = getEnv();
    return sensorObject;
}
