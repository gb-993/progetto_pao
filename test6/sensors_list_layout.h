#ifndef SENSORS_LIST_LAYOUT_H
#define SENSORS_LIST_LAYOUT_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QString>

class SensorsListLayout: public QWidget {
private:
    QLabel *sensorsLabel;
    QComboBox *sensorComboBox;
    QVBoxLayout *layout;
public:
    SensorsListLayout();
    void addButton(QString);
};

#endif // SENSORS_LIST_LAYOUT_H



