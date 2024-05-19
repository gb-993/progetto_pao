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

class Sensor: public QObject {
    Q_OBJECT
private:
    int id;
    QString name;
    QString type;
    QString environment;

    static int counter;
    int generateId() const;
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

    // metodi set
    virtual void setName(const QString&);
    virtual void setType(const QString&);
    virtual void setEnv(const QString&);
    virtual void setSimulationData(const QList<QPointF>&);
    virtual void genSimulation() =0;

    virtual bool has_simulation_data() const;
    virtual void print_sensor() const;

    // metodi serializzazione
    virtual QJsonObject sensorToJson() =0;
    static Sensor* jsonToSensor(const QJsonValue&); // ancora da implementare


    virtual ~Sensor() {}
};

//Sensor* jsonToSensor(const QJsonValue&);

#endif // SENSOR_H
