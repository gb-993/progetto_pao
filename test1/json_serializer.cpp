#include "json_serializer.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

JsonSerializer::JsonSerializer(QObject *parent) : QObject(parent) {}

void JsonSerializer::saveToJson(const QString &filename, const QJsonObject &jsonObject) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QJsonDocument jsonDoc(jsonObject);
        file.write(jsonDoc.toJson());
        file.close();
    }
}

QJsonObject JsonSerializer::loadFromJson(const QString &filename) {
    QFile file(filename);
    QJsonObject jsonObject;
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
        jsonObject = jsonDoc.object();
        file.close();
    }
    return jsonObject;
}





/*
parte seria
Viene definita una funzione saveDataToJson che accetta tre parametri:
sensors: una lista di oggetti Sensor.
simulation: un oggetto Simulation.
filename: il percorso del file JSON in cui salvare i dati.
*/
void saveDataToJson(const QList<Sensor>& sensors, const Simulation& simulation, const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Impossibile aprire il file per la scrittura:" << file.errorString();
        return;
    }

    QJsonObject dataObject;     // contiene tutti i dati da serializzare
    QJsonArray sensorsArray;    // memorizza i dati di iascun sensore

    // Serializza i dati dei sensori
    for (const auto& sensor : sensors) {            // per ogni sensore nella lista
        QJsonObject sensorObject;                   // creo un oggetto apposito
        //sensorObject["id"] = sensor.getId();        // gli attribuisco i dati
        sensorObject["name"] = sensor.getName();
        sensorObject["type"] = sensor.getType();

        // Serializza i dati di simulazione del sensore, se presenti
        if (sensor.has_simulation_data()) {

            QJsonArray simulationDataArray;

            const QList<QPointF>& simulationData = sensor.getSimulationData();

            for (const auto& point : simulationData) {
                QJsonObject pointObject;
                pointObject["x"] = point.x();
                pointObject["y"] = point.y();
                simulationDataArray.append(pointObject);
            }

            sensorObject["simulationData"] = simulationDataArray;
        }

        sensorsArray.append(sensorObject);
    }

    // Serializza i dati della simulazione
    QJsonObject simulationObject;
    // Aggiungi qui i dati della simulazione
    dataObject["sensors"] = sensorsArray;
    dataObject["simulation"] = simulationObject;

    QJsonDocument saveDoc(dataObject);
    file.write(saveDoc.toJson());
    file.close();
}
