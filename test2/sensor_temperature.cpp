#include "sensor_temperature.h"

Sensor_temperature::Sensor_temperature(QString n, QString t, QString e, double l, double u): Sensor(n, t, e), lower(l), upper(u) {}

double Sensor_temperature::getLower() const {
    return lower;
}
double Sensor_temperature::getUpper() const {
    return upper;
}

void Sensor_temperature::setLower(const double& l) {
    lower = l;
}
void Sensor_temperature::setUpper(const double& u) {
    upper = u;
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
