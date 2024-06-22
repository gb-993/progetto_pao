#ifndef SENSORS_LIST_LAYOUT_H
#define SENSORS_LIST_LAYOUT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "custom_button.h"

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
    void showInfo(QPointer<Sensor>);
    void sendSensor(QPointer<Sensor>);
signals:
    void showInfoSignal(Sensor*);
    void sendSensorSignal(Sensor*);
public:
    SensorsListLayout(QWidget* parent = nullptr);
    void addButton(Sensor*);
    virtual void notify(Sensor&);
    void clearLayout();
    QList<CustomButton*>* getButtonsList();
    QLabel* getLabel() const;
    void removeOneButton(CustomButton*);
};

#endif // SENSORS_LIST_LAYOUT_H
