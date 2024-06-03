#ifndef SENSOR_H
#define SENSOR_H

#include <QString>
#include <QList>
#include <QPointF>
#include <QObject>
#include <QDebug>
#include <QRandomGenerator>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include "sensor_observer_interface.h"
#include "sensor_visitor_interface.h"

class Sensor {
private:
    int id;
    QString name;
    QString type;
    QString environment;

    static int counter;
    int generateId() const;

    QVector<Sensor_observer_interface*> observers;
protected:
    QList<QPointF> simulationData;
public:
    Sensor(QString, QString, QString);

    // metodi get
    virtual int getId() const;
    virtual QString getName() const;
    virtual QString getType() const;
    virtual QString getEnv() const;
    virtual QList<QPointF> getSimData() const;
    virtual QList<QString> getInfo() const;

    // metodi set
    virtual void setName(const QString&);
    virtual void setType(const QString&);
    virtual void setEnv(const QString&);
    virtual void setSimulationData(const QList<QPointF>&);
    virtual void genSimulation() =0;

    virtual bool has_simulation_data() const;
    virtual void print_sensor() const;

    // metodi Observer
    virtual void addObserver(Sensor_observer_interface*);
    virtual void notifyObservers(Sensor&);

    // metodi Visitor
    virtual void accept(SensorVisitorInterface& visitor) = 0;

    // metodi serializzazione
    QJsonObject sensorToJsonCommonField();
    virtual QJsonObject sensorToJson() =0;
    static Sensor* jsonToSensor(const QJsonValue&); // dove è implementato?

    virtual ~Sensor() {}
};


#endif // SENSOR_H
