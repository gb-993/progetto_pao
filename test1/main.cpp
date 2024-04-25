#include "mainwindow.h"
#include "sensor.h"
#include "sensor_manager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // test classe sensor
    Sensor s1("ciao", "tipostrano");
    s1.print_sensor();
    s1.setName("s1");
    s1.setType("tipo1");
    s1.print_sensor();
    Sensor s2("s2");
    s2.print_sensor();

    // test classe SensorManager
    SensorManager sm1 ;
    sm1.print_sensor_list();
    sm1.addSensor(&s1);
    sm1.addSensor(&s2);
    QList<Sensor*> sensoriTot;
    sensoriTot = sm1.getSensors();
    sm1.print_sensor_list();

    return a.exec();
}
