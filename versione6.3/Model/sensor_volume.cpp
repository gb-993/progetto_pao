#include "sensor_volume.h"

Sensor_volume::Sensor_volume(QString n, QString t, QString e, double u): Sensor(n, t, e), upper(u) {}

double Sensor_volume::getUpper() const {
    return upper;
}
QList<QString> Sensor_volume::getInfo() const{
    QList<QString> list;
    list = Sensor::getInfo();
    list.append(QString::number(getUpper()));
    return list;
}

void Sensor_volume::setUpper(const double& u) {
    upper = u;
    notifyObservers(*this);
}

void Sensor_volume::print_sensor() const {
    qDebug()<<getId()<<getName()<<getType()<<getEnv()<<getUpper();
    if(has_simulation_data()){
        qDebug() << "Lista di punti: ";
        for (const QPointF &point : getSimData()) {
            qDebug() << "(" << point.x() << "," << point.y() << ")";
        }
    }
}

void Sensor_volume::genSimulation() {
    //pulisce la lista della simulazione precedente
    simulationData.clear();

    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    int val = 0;
    double x = 0.0;
    double y = upper;
    QList<QPointF> p;
    for(int i = 0; i < 100; i ++) {
        x += 1.0;
        val = generator.bounded(1,5);
        if ((y-val) >= 0){
            y -= val;
        } else {
            y = 0;
        }
        p.append(QPointF(x, y)); // aggiunge il punto alla lista
    }
    setSimulationData(p);
}

void Sensor_volume::accept(SensorVisitorInterface& visitor) {
    visitor.visitVolume(*this);
}

// applicato su un sensore, return un QJsonObject che è un singolo sensore in formato json
QJsonObject Sensor_volume::sensorToJson(){
    // creo l'oggetto json che contiene i campi del sensore (name, type, id, simulationData)
    /*
    QJsonObject sensorObject;
    sensorObject["id"] = getId();
    sensorObject["name"] = getName();
    sensorObject["type"] = getType();
    sensorObject["environment"] = getEnv();
    */

    QJsonObject sensorObject = Sensor::sensorToJsonCommonField();
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

Sensor_volume* Sensor_volume::jsonToSensor(const QJsonValue& sensorValue){
    // SENSOR <- RICEVE QUESTO "SENSOR VALUE"
    QJsonObject sensorObject = sensorValue.toObject();

    // Estrarre il nome e il tipo del sensore dall'oggetto JSON
    //int id = sensorObject["id"].toInt();
    // DA FARE IN UNA FUNZIONE COMUNE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    QString name = sensorObject["name"].toString();
    QString type = sensorObject["type"].toString();
    QString environment = sensorObject["environment"].toString();

    double upper = sensorObject["Max Value"].toDouble();

    // Creare un nuovo sensore e aggiungerlo alla lista dei puntatori a sensori
    Sensor_volume* sensor = new Sensor_volume(name, type, environment, upper);

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
