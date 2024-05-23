#ifndef CREATE_SENSOR_WINDOW_H
#define CREATE_SENSOR_WINDOW_H

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

class CreateSensorWindow: public QWidget {
    Q_OBJECT
private:
    QLabel *label;
    QLineEdit *textName;
    QComboBox *menuType;
    QComboBox *textLower;
    QComboBox *textUpper;
    QComboBox *menuEnv;
    QComboBox *menuStatusLight;
    QComboBox *menuFilter;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QVBoxLayout *mainLayout;
    QVBoxLayout* specificLayout;
private slots:
    void updateWidgets();
public:
    CreateSensorWindow();
};

#endif // CREATE_SENSOR_WINDOW_H
