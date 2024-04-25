// MODEL

#include "sensor.h"


// non ricordo se qua va definito qualcosa
Sensor::Sensor()  {}

Sensor::Sensor(const QString &n, const QString &t): name(n), type(t) {}

void Sensor::setName(const QString& n) {
    name = n;
}

void Sensor::setType(const QString& t) {
    type = t;
}

QString Sensor::getName() const {
    return name;
}

QString Sensor::getType() const {
    return type;
}

void Sensor::print_sensor() const{
    qDebug()<<getName()<<getType();
}
