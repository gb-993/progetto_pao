#ifndef CUSTOM_BUTTON_H
#define CUSTOM_BUTTON_H

#include <QPushButton>
#include <QString>
#include <QPointer>
#include "../Model/sensor.h"

class CustomButton: public QPushButton {
    Q_OBJECT
private:
    QPointer<Sensor> sensor;
    QString name;
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
