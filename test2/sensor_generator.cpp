#include <sensor_generator.h>

Sensor* Sensor_generator::jsonToSensor(const QJsonValue& sensorValue){
    // SENSOR <- RICEVE QUESTO "SENSOR VALUE"
    QJsonObject sensorObject = sensorValue.toObject();
    // Estrarre il nome e il tipo del sensore dall'oggetto JSON
    // deve estrarre tutti gli attributi che trova.. in base a quelli che trova creare un sensor delt ipo giusto

    //int id = sensorObject["id"].toInt();
    QString name = sensorObject["name"].toString();
    QString type = sensorObject["type"].toString();
    QString environment = sensorObject["environment"].toString();
    QJsonArray simulationDataArray = sensorObject["simulationData"].toArray();
    QList<QPointF> simulationData;
    // Creare un nuovo sensore e aggiungerlo alla lista dei puntatori a sensori
    // con più tipi di sensore come fare? non è un metodo di istanza
    //Sensor* sensor = new Sensor(name, type, environment );

    if (sensorObject.contains("simulationData")) {
        // QJsonArray simulationDataArray = sensorObject["simulationData"].toArray();
        // QList<QPointF> simulationData;
        for (const auto& pointValue : simulationDataArray) {
            QJsonObject pointObject = pointValue.toObject();
            qreal x = pointObject["x"].toDouble();
            qreal y = pointObject["y"].toDouble();
            simulationData.append(QPointF(x, y));
        }
            //sensor->setSimulationData(simulationData);
    }


    if (type == "humidity"){
        double lower = sensorObject["lower"].toDouble();
        double upper = sensorObject["upper"].toDouble();
        Sensor_humidity* sensor = new Sensor_humidity(name, type, environment, lower, upper );
        sensor->setSimulationData(simulationData);
        return sensor;


    }
    else if (type == "filter"){
        int filterChanged = sensorObject["filterChanged"].toInt();
        Sensor_filter* sensor = new Sensor_filter(name, type, environment, filterChanged );
        sensor->setSimulationData(simulationData);
        return sensor;


    }
    else if (type == "light"){
        bool status = sensorObject["status"].toBool();
        Sensor_light* sensor = new Sensor_light(name, type, environment, status );
        sensor->setSimulationData(simulationData);
        return sensor;


    }
    else if (type == "temperature"){
        double lower = sensorObject["lower"].toDouble();
        double upper = sensorObject["upper"].toDouble();
        Sensor_temperature* sensor = new Sensor_temperature(name, type, environment, lower, upper );
        sensor->setSimulationData(simulationData);
        return sensor;


    }
    else if (type == "volume"){
        double upper = sensorObject["upper"].toDouble();
        Sensor_volume* sensor = new Sensor_volume(name, type, environment, upper );
        sensor->setSimulationData(simulationData);
        return sensor;

    }
    else {
        return nullptr;
    }
}
