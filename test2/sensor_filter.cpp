#include "sensor_filter.h"

Sensor_filter::Sensor_filter(QString n, QString t, QString e, int f): Sensor(n, t, e), filterChanged(f) {}

int Sensor_filter::getFil() const {
    return filterChanged;
}

void Sensor_filter::setFil(const int& f) {
    filterChanged = f;
}

void Sensor_filter::print_sensor() const {
    qDebug()<<getId()<<getName()<<getType()<<getEnv()<<getFil();
    if(has_simulation_data()){
        qDebug() << "Lista di punti: ";
        for (const QPointF &point : getSimData()) {
            qDebug() << "(" << point.x() << "," << point.y() << ")";
        }
    }
}

void Sensor_filter::genSimulation() {
    //pulisce la lista della simulazione precedente
    simulationData.clear();

    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    int val = 0;
    int x = 0;
    int y = 0;
    QList<QPointF> p;
    for(int i = 0; i < 100; i ++) {
        val = generator.bounded(1,4);
        x += 1.0;
        y += val;
        p.append(QPointF(x, y)); // aggiunge il punto alla lista
    }
    setSimulationData(p);
}
