#ifndef MODIFY_SENSOR_WINDOW_H
#define MODIFY_SENSOR_WINDOW_H

#include <QDialog>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"
#include "sensor_modify_visitor.h"

class ModifySensorWindow: public QWidget {
    Q_OBJECT
private:
    QLabel *label;
    QLineEdit *textName;
    QLineEdit *textLower;
    QLineEdit *textUpper;
    QComboBox *menuEnv;
    QComboBox *menuStatusLight;
    QComboBox *menuFilter;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QVBoxLayout *mainLayout;
    SensorModifyVisitor* visitor;
public:
    ModifySensorWindow();
};

#endif // MODIFY_SENSOR_WINDOW_H
