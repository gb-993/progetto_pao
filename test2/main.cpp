#include "mainwindow.h"
#include "sensor.h"
#include "sensor_light.h"
#include "sensor_humidity.h"
#include "sensor_temperature.h"
#include "sensor_volume.h"
#include "sensor_filter.h"
#include "sensor_manager.h"
#include <QApplication>
#include <controller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*
    // test classe Sensor_light
    qDebug() << "Test classe Sensor_light";
    Sensor_light s1;
    s1.genSimulation();
    //s1.print_sensor();

    // test classe Sensor_humidity
    qDebug() << "Test classe Sensor_humidity";
    Sensor_humidity s2;
    s2.genSimulation();
    //s2.print_sensor();

    // test classe Sensor_temperature
    qDebug() << "Test classe Sensor_temperature";
    Sensor_temperature s3;
    s3.genSimulation();
    //s3.print_sensor();

    // test classe Sensor_volume
    qDebug() << "Test classe Sensor_volume";
    Sensor_volume s4;
    s4.genSimulation();
    s4.print_sensor();

    // test classe Sensor_filter
    qDebug() << "Test classe Sensor_filter";
    Sensor_filter s5;
    s5.genSimulation();
    //s5.print_sensor();

    // test classe Sensor_manager
    qDebug() << "Test classe Sensor_manager";
    Sensor_manager sm;
    sm.addSensor(&s1);
    sm.addSensor(&s2);
    sm.addSensor(&s3);
    sm.addSensor(&s4);
    sm.addSensor(&s5);
    //sm.print_sensor_list();
    //sm.removeSensor(&s3);
    //sm.print_sensor_list();
    */
    Sensor_manager sm;
    Controller c1;


    // c1.func_save(sm, "C:/Users/gbmat/Desktop/progetto_pao/test2/jsondata.txt");
    c1.func_load("C:/Users/gbmat/Desktop/progetto_pao/test2/jsondata.txt",sm);
    sm.print_sensor_list();

    return a.exec();
}
