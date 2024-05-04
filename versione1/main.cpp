#include "mainwindow.h"
#include "sensor.h"
#include "sensor_manager.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // test classe Sensor
    /*
    qDebug() << "Test classe Sensor";
    Sensor s1;
    s1.setSimulation();
    Sensor s2;
    s2.setSimulation();
    Sensor s3;
    s3.setSimulation();
    Sensor s4;
    s4.setSimulation();
    s1.print_sensor();
    s2.print_sensor();
    s3.print_sensor();
    s4.print_sensor();
    */

    // test classe Sensor_manager
    /*
    qDebug() << "Test classe Sensor_manager";
    SensorManager sm;
    sm.addSensor(&s1);
    sm.addSensor(&s2);
    sm.addSensor(&s3);
    sm.addSensor(&s4);
    sm.print_sensor_list();
    sm.removeSensor(&s3);
    sm.print_sensor_list();

    qDebug()<<"test classe sensor";
    Sensor s1("ciao", "tipostrano");
    s1.print_sensor();
    s1.setName("s11");
    s1.setType("tipo1");
    qDebug()<<"sensore s1 modificato: ";
    s1.print_sensor();
    Sensor s2("s2");
    s2.print_sensor();
    qDebug()<<"";

    SensorManager sm1;
    qDebug()<<"sm1 vuoto: ";
    sm1.print_sensor_list();
    sm1.addSensor(&s1);
    sm1.addSensor(&s2);
    qDebug()<<"riempito con s1 e s2: ";
    sm1.print_sensor_list();
    sm1.removeSensor(&s2);
    qDebug()<<"rimosso s2: ";
    sm1.print_sensor_list();
    qDebug()<<"";
    */

    //test simulazione
    /*
    qDebug()<<"test simulazione: ";
    Sensor s3("s3", "test");
    qDebug()<<"sensore s3: ";
    s3.print_sensor();
    qDebug()<<"s3.hasSimulationData?";
    qDebug() << s3.has_simulation_data();
    s3.setSimulation();
    qDebug()<<"settata la simulazione";
    qDebug()<<"s3.hasSimulationData?";
    qDebug() << s3.has_simulation_data();
    s3.print_sensor();
    sm1.addSensor(&s3);
    Sensor s4;
    sm1.addSensor(&s4);
    qDebug()<<"aggiunto s4 tutto default";
    sm1.print_sensor_list();
    qDebug()<<"";
    */

    // test serializzazione
    /*
    qDebug()<<"test serializzazione";
    Controller c1;
    c1.func_save(sm, "C:/Users/cater/OneDrive/Desktop/Uni/Secondoanno/P2/DocumentiProgetto/versione1/salvataggio.txt");
    c1.func_load("C:/Users/cater/OneDrive/Desktop/Uni/Secondoanno/P2/DocumentiProgetto/versione1/salvataggio.txt", sm);
    sm.print_sensor_list();
    */


    return a.exec();
}
