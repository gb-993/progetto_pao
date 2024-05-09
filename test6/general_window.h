#ifndef GENERAL_WINDOW_H
#define GENERAL_WINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPixmap>
#include <QLabel>
#include "top_layout.h"
#include "sensors_list_layout.h"
#include "single_sensor_layout.h"

class GeneralWindow: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *bottomLayout;
    TopLayout* top;
    SensorsListLayout* sensors_list;
    SingleSensorLayout* single_sensor;
public:
    GeneralWindow ();
};

#endif // GENERAL_WINDOW_H
