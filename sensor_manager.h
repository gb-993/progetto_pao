// MODEL
// gestisce i sensori nel loro insieme, non si cura delle caratteristiche di ognuno
// circa come la classe Rubrica per i contatti
// forse ha senso farlo diventare direttamente una lista

#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <QObject>
#include <QList>
#include "Sensor.h"

class SensorManager : public QObject {
    Q_OBJECT
private:
    QList<Sensor*> all_sensors; // Lista dei sensori, dovrebbe essere inizializzata dal costruttore --> FATTO
public:
    SensorManager();
    // metodi get
    QList<Sensor *> getSensors() const;
    // Funzioni per la gestione dei sensori
    void addSensor(Sensor *sensor);
    void removeSensor(Sensor *sensor);
    void print_sensor_list();
};

#endif // SENSORMANAGER_H
