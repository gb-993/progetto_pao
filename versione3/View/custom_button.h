#ifndef CUSTOM_BUTTON_H
#define CUSTOM_BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

class CustomButton: public QPushButton{
    Q_OBJECT
private:
    QString name;
    Sensor* sensor;
private slots:
    void buttonClicked();
signals:
    void buttonClickedSignal(Sensor*);
public:
    CustomButton(QString, Sensor*, QPushButton* parent = nullptr);
    void setSensor(Sensor*);
    Sensor& getSensor() const;
    int getId() const;
};

#endif // CUSTOM_BUTTON_H
