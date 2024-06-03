#ifndef SENSORS_LIST_LAYOUT_H
#define SENSORS_LIST_LAYOUT_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include "custom_button.h"
#include "../Model/sensor.h"
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

class SensorsListLayout: public QWidget {
    Q_OBJECT
private:
    // serve un array di pushBUtton ( custom o meno )
    // così quando aggiungo un pushbutton, questa classe vede l'istanza (?)
    // altrimenti non posso vederla e nessuna classe la vede e non posso ricevere la signal
    QLabel *sensorsLabel;
    QLineEdit *searchBar;
    QVBoxLayout *layout;
    QVBoxLayout *buttonsLayout;
    QList<CustomButton> buttonList;

private slots:
    void searchTextChanged(const QString&);
    void callToController(Sensor* s);

signals:
    void callToControllerSignal(Sensor*);

public:
    SensorsListLayout();
    void addButton(Sensor*, QList<CustomButton>*);
    void addButtonToLayout(QList<CustomButton*>*);
    void clearLayout(QVBoxLayout*);
    QVBoxLayout* getLayout() const;
    QList<CustomButton>* getButtonList() const;

};

#endif // SENSORS_LIST_LAYOUT_H
