#include "sensor_light.h"

Sensor_light::Sensor_light(QString n, QString t, QString e, bool s): Sensor(n, t, e), status(s) {}

int Sensor_light::getStatus() const {
    return status;
}

void Sensor_light::setStatus(const bool& s) {
    status = s;
}

void Sensor_light::print_sensor() const {
    qDebug()<<getId()<<getName()<<getType()<<getEnv()<<getStatus();
    if(has_simulation_data()){
        qDebug() << "Lista di punti: ";
        for (const QPointF &point : getSimData()) {
            qDebug() << "(" << point.x() << "," << point.y() << ")";
        }
    }
}

void Sensor_light::genSimulation() {
    //pulisce la lista della simulazione precedente
    simulationData.clear();

    //genera punti causali
    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    int x = 0;
    int y = 0;
    for(int i = 0; i < 100; i ++) {
        x += 1;
        y = generator.bounded(0,2);
        simulationData.append(QPointF(x, y)); // aggiunge il punto alla lista
    }
}

