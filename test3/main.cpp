#include "mainwindow.h"
#include "sensor.h"
#include "sensor_manager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // test classe Sensor
    qDebug() << "Test classe Sensor";
    Sensor s1;
    s1.setSimulation();
    Sensor s2;
    s2.setSimulation();
    Sensor s3;
    s3.setSimulation();
    Sensor s4;
    s4.setSimulation();

    // test classe Sensor_manager
    qDebug() << "Test classe Sensor_manager";
    Sensor_manager sm;
    sm.addSensor(&s1);
    sm.addSensor(&s2);
    sm.addSensor(&s3);
    sm.addSensor(&s4);
    sm.print_sensor_list();
    sm.removeSensor(&s3);
    sm.print_sensor_list();

    return a.exec();
}

