#include "sensor_generator.h"

// legge file json e crea un sensore del tipo adeguato
Sensor* Sensor_generator::jsonToSensor(const QJsonValue& sensorValue){
    QJsonObject sensorObject = sensorValue.toObject();

    QString name = sensorObject["name"].toString();
    QString type = sensorObject["type"].toString();
    QString environment = sensorObject["environment"].toString();
    QJsonArray simulationDataArray = sensorObject["simulationData"].toArray();
    QList<QPointF> simulationData;

    if (sensorObject.contains("simulationData")) {
        for (const auto& pointValue : simulationDataArray) {
            QJsonObject pointObject = pointValue.toObject();
            qreal x = pointObject["x"].toDouble();
            qreal y = pointObject["y"].toDouble();
            simulationData.append(QPointF(x, y));
        }
    }
    if (type == "Humidity"){
        double lower = sensorObject["Min Value"].toDouble();
        double upper = sensorObject["Max Value"].toDouble();
        Sensor_humidity* sensor = new Sensor_humidity(name, type, environment, lower, upper );
        sensor->setSimulationData(simulationData);
        return sensor;
    }
    else if (type == "Filter Changed"){
        int filterChanged = sensorObject["Filter Changed"].toInt();
        Sensor_filter* sensor = new Sensor_filter(name, type, environment, filterChanged );
        sensor->setSimulationData(simulationData);
        return sensor;
    }
    else if (type == "Light"){
        bool status = sensorObject["Light Status"].toBool();
        Sensor_light* sensor = new Sensor_light(name, type, environment, status );
        sensor->setSimulationData(simulationData);
        return sensor;
    }
    else if (type == "Temperature"){
        double lower = sensorObject["Min Value"].toDouble();
        double upper = sensorObject["Max Value"].toDouble();
        Sensor_temperature* sensor = new Sensor_temperature(name, type, environment, lower, upper );
        sensor->setSimulationData(simulationData);
        return sensor;
    }
    else if (type == "Volume"){
        double upper = sensorObject["Max Value"].toDouble();
        Sensor_volume* sensor = new Sensor_volume(name, type, environment, upper );
        sensor->setSimulationData(simulationData);
        return sensor;
    }
    else {
        return nullptr;
    }
}
