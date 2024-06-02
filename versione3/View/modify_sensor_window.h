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
#include "custom_button.h"

class ModifySensorWindow: public QDialog {
    Q_OBJECT
private:
    QLabel *label;
    QLineEdit *textName;
    QComboBox *menuEnv;
    CustomButton *saveButton;
    QPushButton *cancelButton;
    QVBoxLayout *mainLayout;
    QVBoxLayout *buttonLayout;
    QVBoxLayout *settingsLayout;
    SensorModifyVisitor* visitor;
    QComboBox* menu;
    QComboBox* menu2;
private slots:
    void saveButtonClicked(Sensor*);
    void cleanFields();
signals:
    void saveButtonClickedSignal(Sensor*);
public:
    ModifySensorWindow(QDialog* parent = nullptr);
    void setUpModify(Sensor*);
    QString getName() const;
    QString getEnv() const;
    QString getMenu() const;
    QString getMenu2() const;
};

#endif // MODIFY_SENSOR_WINDOW_H
