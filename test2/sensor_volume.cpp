#include "sensor_volume.h"

Sensor_volume::Sensor_volume(QString n, QString t, QString e, double l, double u): Sensor(n, t, e), lower(l), upper(u) {}

double Sensor_volume::getLower() const {
    return lower;
}
double Sensor_volume::getUpper() const {
    return upper;
}

void Sensor_volume::setLower(const double& l) {
    lower = l;
}
void Sensor_volume::setUpper(const double& u) {
    upper = u;
}

void Sensor_volume::print_sensor() const {
    qDebug()<<getId()<<getName()<<getType()<<getEnv()<<getLower()<<getUpper();
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
