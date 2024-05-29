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

class CreateSensorWindow: public QDialog {
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
    QPushButton *createButton;
    QPushButton *cancelButton;
    QVBoxLayout *mainLayout;
    QVBoxLayout* specificLayout;
private slots:
    void updateWidgets();
    void createButtonClicked();
signals:
    void createButtonClickedSignal();
public:
    CreateSensorWindow();
    int getId() const;
    QString getName() const;
    QString getType() const;
    QString getEnv() const;
    int getFilter() const;
    double getLower() const;
    double getUpper() const;
    bool getStatus() const;
};

#endif // CREATE_SENSOR_WINDOW_H
