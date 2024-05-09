#include "sensor.h"
// DA SISTEMARE CODICE ID
Sensor::Sensor(QString n, QString t, double l, double u, QString e, QString mu): id(generateId()), name(n), type(t), lower(l), upper(u), environment(e), measure_unit(mu), simulationData() {}

int Sensor::counter = 0; // Variabile statica per tenere traccia del contatore
int Sensor::generateId() const {
    return ++counter;
}
void Sensor::setName(const QString& n) {
    name = n;
    notifyObservers(*this);
}
void Sensor::setType(const QString& t) {
    type = t;
    notifyObservers(*this);
}
void Sensor::setLower(const double& l) {
    lower = l;
    notifyObservers(*this);
}
void Sensor::setUpper(const double& u) {
    upper = u;
    notifyObservers(*this);
}
void Sensor::setEnv(const QString& e) {
    environment = e;
    notifyObservers(*this);
}
void Sensor::setMU(const QString& mu) {
    measure_unit = mu;
    notifyObservers(*this);
}

//DA SISTEMARE, va messo notifyObservers(*this);?
void Sensor::setSimulation() {
    //pulisce la lista della simulazione precedente
    simulationData.clear();

    //genera punti causali
    QRandomGenerator generator;
    int x = 0;
    int y = 0;
    //QPointF p;
    for(int i = 0; i < 5; i ++) {
        x += 1;
        y += 2;
        simulationData.append(QPointF(x, y)); // aggiunge il punto alla lista
    }
}
// DA TENERE PER FORZA
void Sensor::setSimulationData(const QList<QPointF>& p){
    simulationData.append(p);
}


QString Sensor::getName() const {
    return name;
}
int Sensor::getId() const {
    return id;
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
QList<QPointF> Sensor::getSimulationData() const{
    return simulationData;
}
bool Sensor::has_simulation_data() const{
    if(simulationData.empty()) return false;
    return true;
}

void Sensor::print_sensor() const {
    qDebug()<<"Id: "<<getId()<<"Nome: "<<getName()<<"Tipo: "<<getType()<<"Minimo: "<<getLower()<<"Massimo: "<<getUpper()<<"Ambiente: "<<getEnv()<<"Unità di misura: "<<getMU();
    if(has_simulation_data()){
        qDebug() << "Lista di punti: ";
        for (const QPointF &point : getSimulationData()) {
            qDebug() << "(" << point.x() << "," << point.y() << ")";
        }
    }
}

// applicato su un sensore, return un QJsonObject che è un singolo sensore in formato json
QJsonObject Sensor::sensorToJson(){
    // creo l'oggetto json che contiene i campi del sensore (name, type, id, simulationData)
    QJsonObject sensorObject;
    sensorObject["name"] = getName();
    sensorObject["type"] = getType();
    sensorObject["id"] = getId();
    sensorObject["lower"] = getLower();
    sensorObject["upper"] = getUpper();
    sensorObject["environment"] = getEnv();
    sensorObject["measure_unit"] = getMU();

    if (has_simulation_data()) {
        QJsonArray simulationDataArray;
        const QList<QPointF>& dati_simulazione = getSimulationData();
        for (const auto& point : dati_simulazione) {
            QJsonObject pointObject;
            pointObject["x"] = point.x();
            pointObject["y"] = point.y();
            simulationDataArray.append(pointObject);
        }
        sensorObject["simulationData"] = simulationDataArray;
    }
    return sensorObject;
}

Sensor* jsonToSensor(const QJsonValue& sensorValue){
    // SENSOR <- RICEVE QUESTO "SENSOR VALUE"
    QJsonObject sensorObject = sensorValue.toObject();
    // Estrarre il nome e il tipo del sensore dall'oggetto JSON
    QString name = sensorObject["name"].toString();
    QString type = sensorObject["type"].toString();
    //int id = sensorObject["id"].toInt();
    double lower = sensorObject["lower"].toDouble();
    double upper = sensorObject["upper"].toDouble();
    QString environment = sensorObject["environment"].toString();
    QString measure_unit = sensorObject["measure_unit"].toString();

    // Creare un nuovo sensore e aggiungerlo alla lista dei puntatori a sensori
    Sensor* sensor = new Sensor(name, type, lower, upper, environment, measure_unit);

    if (sensorObject.contains("simulationData")) {
        QJsonArray simulationDataArray = sensorObject["simulationData"].toArray();
        QList<QPointF> simulationData;
        for (const auto& pointValue : simulationDataArray) {
            QJsonObject pointObject = pointValue.toObject();
            qreal x = pointObject["x"].toDouble();
            qreal y = pointObject["y"].toDouble();
            simulationData.append(QPointF(x, y));
        }
        sensor->setSimulationData(simulationData);
    }
    return sensor;
}

void Sensor::addObserver(Sensor_observer_interface *obs) {
    observers.push_back(obs); // aggiungo osservatore alla lista
}
void Sensor::notifyObservers(Sensor& s){
    for(auto obs=observers.begin(); obs!=observers.end(); obs++){
        (*obs)->notify(s);
    }
}

