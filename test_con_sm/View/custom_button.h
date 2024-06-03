#ifndef CUSTOM_BUTTON_H
#define CUSTOM_BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include "../Model/sensor.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_light.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

class CustomButton: public QPushButton {
    Q_OBJECT

private:
    Sensor* sensor;
private slots:
    void showInfo(Sensor*);
    void setUpModify(Sensor*);
signals:
    void showInfoSignal(Sensor*);
    void setUpModifySignal(Sensor*);
public:
    CustomButton(Sensor*, QPushButton* parent = nullptr);
    QString getName() const;
    Sensor* getSensor() const;
};

#endif // CUSTOM_BUTTON_H
