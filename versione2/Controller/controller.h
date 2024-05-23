#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include "../Model/sensor_manager.h"

class Controller {
public:
    Controller();

    void func_save(Sensor_manager& ,const QString& );
    void func_load(const QString&, Sensor_manager& );

    // distruttore
    virtual ~Controller() {}
};


#endif // CONTROLLER_H
