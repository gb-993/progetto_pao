#ifndef SENSOR_H
#define SENSOR_H

#include <QString>
#include <QList>
#include <QPointF>
#include <QObject>
#include <QDebug>
#include <QRandomGenerator>

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

public:
    Sensor(QString ="default_name", QString ="default_type", double =0, double =0, QString ="default_environment", QString ="default_measure_unit");

    // metodi get
    int getId() const;
    QString getName() const;
    QString getType() const;
    double getLower() const;
    double getUpper() const;
    QString getEnv() const;
    QString getMU() const;
    QList<QPointF> getSimData() const;

    // metodi set
    void setName(const QString&);
    void setType(const QString&);
    void setLower(const double&);
    void setUpper(const double&);
    void setEnv(const QString&);
    void setMU(const QString&);
    void setSimulation();

    bool has_simulation_data() const;
    void print_sensor() const;

    ~Sensor() {}
};

#endif // SENSOR_H
