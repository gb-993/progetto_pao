// MODEL

#ifndef SENSOR_H
#define SENSOR_H

#include <QString>
#include <QList>
#include <QPointF>
#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QRandomGenerator>
#include <QJsonValue>
#include "sensor_observer_interface.h"

class Sensor: public QObject {
    Q_OBJECT
private:
    int id;
    QString name;
    QString type;
    double lower;
    double upper;
    QString environment;
    QString measure_unit;
    QList<QPointF> simulationData;
    static int counter;
    int generateId() const;
    QVector<Sensor_observer_interface*> observers;
public:
    Sensor(QString ="default_name", QString ="default_type", double =0, double =0, QString ="default_environment", QString ="default_measure_unit");

    //metodi set
    void setName(const QString&);
    void setType(const QString&);
    void setLower(const double&);
    void setUpper(const double&);
    void setEnv(const QString&);
    void setMU(const QString&);
    void setSimulation(); //AGGIUNTA IO
    // controllare se serve
    void setSimulationData(const QList<QPointF>&);

    // metodi get
    int getId() const;
    QString getName() const;
    QString getType() const;
    double getLower() const;
    double getUpper() const;
    QString getEnv() const;
    QString getMU() const;
    QList<QPointF> getSimulationData() const;
    bool has_simulation_data() const;
    void print_sensor() const;

    // metodi serializzazione
    QJsonObject sensorToJson();

    // metodi Observer
    void addObserver(Sensor_observer_interface*);

    // distruttore
    virtual ~Sensor() {}
};

Sensor* jsonToSensor(const QJsonValue&);


#endif // SENSOR_H
