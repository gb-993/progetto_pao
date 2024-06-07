#ifndef CUSTOM_BUTTON_H
#define CUSTOM_BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QPointer>
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

class CustomButton: public QPushButton{
    Q_OBJECT
private:
    QString name;
    QPointer<Sensor> sensor;
private slots:
    void buttonClicked();
signals:
    void buttonClickedSignal(QPointer<Sensor>);
public:
    CustomButton(QString, QPushButton* parent = nullptr);
    void setSensor(Sensor*);
    QPointer<Sensor> getSensor() const;
};

#endif // CUSTOM_BUTTON_H
