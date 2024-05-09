#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include "sensor.h"
#include <QFile>
class SensorManager : public QObject {
    Q_OBJECT
private:
    QList<Sensor*> all_sensors;
public:
    // costruttore
    SensorManager();

    // metodi get
    QList<Sensor*> getSensors() const;
    //QList<Sensor*>& getSensorPointers() ;
    // Funzioni per la gestione dei sensori
    void addSensor(Sensor *sensor);
    void removeSensor(Sensor *sensor);
    void print_sensor_list();

    // serializer out
    QJsonObject sensorListToJson();
    // serializer in
    void loadDataFromJson(QFile&);

    // distruttore
    virtual ~SensorManager() {}
};

#endif // SENSORMANAGER_H
