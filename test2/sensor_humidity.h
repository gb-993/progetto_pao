#ifndef SENSOR_HUMIDITY_H
#define SENSOR_HUMIDITY_H

#include <QString>
#include <QList>
#include <QPointF>
#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QRandomGenerator>
#include <QJsonValue>
#include <sensor.h>

class Sensor_humidity: public virtual Sensor {
    Q_OBJECT
private:
    double lower;
    double upper;
public:
    Sensor_humidity(QString ="default_name", QString ="humidity", QString ="room", double =70.0, double =80.0); // valori 70 e 80 espressi in percentuale

    double getLower() const;
    double getUpper() const;

    void setLower(const double&);
    void setUpper(const double&);

    void print_sensor() const;

    void genSimulation();

    QJsonObject sensorToJson();
    Sensor_humidity* jsonToSensor(const QJsonValue&);
};

#endif // SENSOR_HUMIDITY_H
