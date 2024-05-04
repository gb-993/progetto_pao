#include "controller.h"

Controller::Controller() {}

void Controller::func_save(SensorManager& sm1, const QString& filename){
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Impossibile aprire il file per la scrittura:" << file.errorString();
        return;
    }
    QJsonDocument saveDoc(sm1.sensorListToJson());
    file.write(saveDoc.toJson());
    file.close();
}

void Controller::func_load(const QString& filename, SensorManager& sm1){
    // CONTROLLER
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        // Errore se non è possibile aprire il file
        qWarning() << "Impossibile aprire il file per la lettura:" << file.errorString();
        return;
    }
    sm1.loadDataFromJson(file);
}

