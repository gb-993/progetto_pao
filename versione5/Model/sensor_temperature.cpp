#include "sensor_temperature.h"

Sensor_temperature::Sensor_temperature(QString n, QString t, QString e, double l, double u): Sensor(n, t, e), lower(l), upper(u) {}

double Sensor_temperature::getLower() const {
    return lower;
}
double Sensor_temperature::getUpper() const {
    return upper;
}
QList<QString> Sensor_temperature::getInfo() const{
    QList<QString> list;
    list = Sensor::getInfo();
    list.append(QString::number(getLower()));
    list.append(QString::number(getUpper()));
    return list;
}

void Sensor_temperature::setLower(const double& l) {
    lower = l;
    notifyObservers(*this);
}
void Sensor_temperature::setUpper(const double& u) {
    upper = u;
    notifyObservers(*this);
}

void Sensor_temperature::print_sensor() const {
    qDebug()<<getId()<<getName()<<getType()<<getEnv()<<getLower()<<getUpper();
    if(has_simulation_data()){
        qDebug() << "Lista di punti: ";
        for (const QPointF &point : getSimData()) {
            qDebug() << "(" << point.x() << "," << point.y() << ")";
        }
    }
}

void Sensor_temperature::genSimulation() {
    //pulisce la lista della simulazione precedente
    simulationData.clear();

    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    double x = 0.0;
    double y = 0.0;
    QList<QPointF> p;
    for(int i = 0; i < 100; i ++) {
        x += 1.0;
        y = generator.bounded(int(lower),int(upper+1));
        p.append(QPointF(x, y)); // aggiunge il punto alla lista
    }
    setSimulationData(p);
}

void Sensor_temperature::accept(SensorVisitorInterface& visitor) {
    visitor.visitTemperature(*this);
}

// applicato su un sensore, return un QJsonObject che è un singolo sensore in formato json
QJsonObject Sensor_temperature::sensorToJson(){
    // creo l'oggetto json che contiene i campi del sensore (name, type, id, simulationData)
    /*
    QJsonObject sensorObject;
    sensorObject["id"] = getId();
    sensorObject["name"] = getName();
    sensorObject["type"] = getType();
    sensorObject["environment"] = getEnv();
    */
    QJsonObject sensorObject = Sensor::sensorToJsonCommonField();
    sensorObject["Min Value"] = getLower();
    sensorObject["Max Value"] = getUpper();

    if (has_simulation_data()) {
        QJsonArray simulationDataArray;
        const QList<QPointF>& dati_simulazione = getSimData();
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



Sensor_temperature* Sensor_temperature::jsonToSensor(const QJsonValue& sensorValue){
    // SENSOR <- RICEVE QUESTO "SENSOR VALUE"
    QJsonObject sensorObject = sensorValue.toObject();

    // Estrarre il nome e il tipo del sensore dall'oggetto JSON
    //int id = sensorObject["id"].toInt();
    QString name = sensorObject["name"].toString();
    QString type = sensorObject["type"].toString();
    QString environment = sensorObject["environment"].toString();

    double lower = sensorObject["Min Value"].toDouble();
    double upper = sensorObject["Max Value"].toDouble();


    // Creare un nuovo sensore e aggiungerlo alla lista dei puntatori a sensori
    Sensor_temperature* sensor = new Sensor_temperature(name, type, environment, lower, upper);

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

