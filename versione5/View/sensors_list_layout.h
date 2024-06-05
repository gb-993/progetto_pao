#ifndef SENSORS_LIST_LAYOUT_H
#define SENSORS_LIST_LAYOUT_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "custom_button.h"
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

class SensorsListLayout: public QWidget, public Sensor_observer_interface  {
    Q_OBJECT
private:
    QLabel *sensorsLabel;
    QLineEdit *searchBar;
    QVBoxLayout *layout;
    QVBoxLayout *buttonsLayout;
    QList<CustomButton*> buttonsList;
private slots:
    void searchTextChanged(const QString&);
    void showInfo(Sensor*);
    void sendSensor(Sensor*);
signals:
    void showInfoSignal(Sensor*);
    void sendSensorSignal(Sensor*);
public:
    SensorsListLayout();
    void addButton(Sensor*);
    virtual void notify(Sensor&);
    void clearLayout();
    QList<CustomButton*> getButtonsList() const;
    QLabel* getLabel() const;
};

#endif // SENSORS_LIST_LAYOUT_H
