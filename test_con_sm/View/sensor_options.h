#ifndef SENSOR_OPTIONS_H
#define SENSOR_OPTIONS_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "modify_sensor_window.h"
#include "confirm_delete_window.h"

class SensorOptions: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* buttonsLayout;
    QPushButton* modify;
    QPushButton* deleteButton;
    QPushButton* start_simulation;
    ConfirmDeleteWindow* confirmWindow;
private slots:
    void showModifyWindow();
signals:
    void showModifyWindowSignal();
public:
    SensorOptions();
};

#endif // SENSOR_OPTIONS_H
