#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include "../View/mainwindow.h"
#include "../View/create_sensor_window.h"
#include "../View/custom_button.h"
#include "../View/sensors_list_layout.h"
#include "../View/top_layout.h"
#include "../View/single_sensor_layout.h"
#include "../View/sensor_options.h"
#include "../View/info_layout.h"
#include "../View/charts_layout.h"
#include "../Model/sensor_manager.h"
#include "../Model/sensor_light.h"
#include "../Model/sensor_filter.h"
#include "../Model/sensor_humidity.h"
#include "../Model/sensor_temperature.h"
#include "../Model/sensor_volume.h"

class Controller: public QObject {
    Q_OBJECT
private:
    MainWindow* mainwindow;
    CreateSensorWindow* createsensorwindow;
    CustomButton* custombutton;
    Sensor* sensor; // BOOOOOH
    SensorsListLayout* sensorslist;
    TopLayout* top;
    SingleSensorLayout* singlesensor;
    SensorOptions* option;
    InfoLayout* info;
    ChartsLayout* chart;
private slots:
    void createSensor(); // crea un sensore, chiamata dalla signal della CreateSensorWindow
    void showSensorInfo(Sensor*);
public:
    Controller(QObject* parent = nullptr);

    void func_save(Sensor_manager& ,const QString& );
    void func_load(const QString&, Sensor_manager& );

    // distruttore
    virtual ~Controller() {}
};


#endif // CONTROLLER_H
