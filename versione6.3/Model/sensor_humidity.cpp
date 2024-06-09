#include "sensor_humidity.h"

Sensor_humidity::Sensor_humidity(QString n, QString t, QString e, double l, double u): Sensor(n, t, e), lower(l), upper(u) {}

// metodi get

double Sensor_humidity::getLower() const {
    return lower;
}
double Sensor_humidity::getUpper() const {
    return upper;
}

QList<QString> Sensor_humidity::getInfo() const{
    QList<QString> list;
    list = Sensor::getInfo();
    list.append(QString::number(getLower()));
    list.append(QString::number(getUpper()));
    return list;
}

// metodi set e chiamata alla lista di osservatori

void Sensor_humidity::setLower(const double& l) {
    lower = l;
    notifyObservers(*this);
}
void Sensor_humidity::setUpper(const double& u) {
    upper = u;
    notifyObservers(*this);
}

// ovveride per generare nuovi dati di simulazione a seconda del tipo di sensore
void Sensor_humidity::genSimulation() {
    simulationData.clear();

    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    double x = 0.0;
    double y = 0.0;
    QList<QPointF> p;
    for(int i = 0; i < 100; i ++) {
        x += 1.0;
        y = generator.bounded(int(lower),int(upper+1));
        p.append(QPointF(x, y));
    }
    setSimulationData(p);
}

// chiama visitFilter sul visitor passato
void Sensor_humidity::accept(SensorVisitorInterface& visitor) {
    visitor.visitHumidity(*this);
}

// trasforma il sensore in un QJsonObject che lo rappresenta
QJsonObject Sensor_humidity::sensorToJson(){
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



Sensor_humidity* Sensor_humidity::jsonToSensor(const QJsonValue& sensorValue){
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
    Sensor_humidity* sensor = new Sensor_humidity(name, type, environment, lower, upper);

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
