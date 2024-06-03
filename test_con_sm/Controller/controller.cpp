#include "controller.h"

Controller::Controller(QObject* parent): QObject(parent) {
    sm = new Sensor_manager();
    option = new SensorOptions();
    info = new InfoLayout();
    chart = new ChartsLayout();
    singlesensor = new SingleSensorLayout(option, info, chart);
    sensorslist = new SensorsListLayout();
    top = new TopLayout();
    mainwindow = new MainWindow(top, sensorslist, singlesensor);
    createsensorwindow = new CreateSensorWindow();
    modifysensorwindow = new ModifySensorWindow();

    mainwindow->showMaximized();

    // partono al create in topLayout
    connect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::resetFields);
    connect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::exec); //questa non si potrebbe spostare da altre parti? non usa &controller come quanrto paramtero

    // parte all'effettivo create dalla dialog
    connect(createsensorwindow, &CreateSensorWindow::createButtonClickedSignal, this, &Controller::createSensor);
    connect(createsensorwindow, &CreateSensorWindow::createButtonClickedSignal, this, &Controller::createSensor);

   // parte al click del myButton
    connect(sensorslist, &SensorsListLayout::callToControllerSignal, this, &Controller::printInfoTest);


}

void Controller::createSensor() {
    QString name = createsensorwindow->getName();
    QString env = createsensorwindow->getEnv();
    QString type = createsensorwindow->getType();
    if (type == "Light") {
        bool status = createsensorwindow->getStatus();
        sensor = new Sensor_light(name,type,env,status);
    } else if (type == "Filter Changed") {
        int filter = createsensorwindow->getFilter();
        sensor = new Sensor_filter(name,type,env,filter);
    } else if (type == "Temperature") {
        double max = createsensorwindow->getUpper();
        double min = createsensorwindow->getLower();
        sensor = new Sensor_temperature(name,type,env,min,max);
    } else if (type == "Humidity"){
        double max = createsensorwindow->getUpper();
        double min = createsensorwindow->getLower();
        sensor = new Sensor_humidity(name,type,env,min,max);
    } else {
        double max = createsensorwindow->getUpper();
        sensor = new Sensor_volume(name,type,env,max);
    }
    createsensorwindow->close();
    // non fa più la addButton ma aggiunge il sensore al sensor manager
    //sensorslist->addButton(sensor);
    sm->addSensor(sensor);
    refresh(sm, sensorslist);
    top->getSaveButton()->setDisabled(false);
}

void Controller::refresh(Sensor_manager* sm, SensorsListLayout* sl) {
    // eliminare tutti i widget da sensorslist
    sl->clearLayout(sl->getLayout());

    // legggere tutti i widget da sm e aggiungerli alla view ( funzione a parte ) ( funzione della view )

    // per ogni sensor di sensorManager (sm->all_sensor) faccio add_button
    QList<Sensor*> sensors = sm->getAllSensor();
    for (int i = 0; i < sensors.length(); ++i) {
        sl->addButton((sensors)[i], sl->getButtonList());
    }

    // per ogni elemento della lista di button, li aggiungo al layout
    QList<CustomButton*> buttonList = *(sl->getButtonList());
    for (int i = 0; i < buttonList.length(); ++i) {
        sl->addButtonToLayout(static_cast<QPushButton*>((*buttonList)[i]));
    }
}



/*
void Controller::showSensorInfo(Sensor* s) {
    singlesensor->setUpOptions(s);
}
void Controller::setUpModify(Sensor* s) {
    modifysensorwindow->setUpModify(s);
}
*/
void Controller::func_save(Sensor_manager& sm1, const QString& filename){
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Impossibile aprire il file per la scrittura:" << file.errorString();
        return;
    }
    QJsonDocument saveDoc(sm1.sensorListToJson());
    file.write(saveDoc.toJson());
    file.close();
}

void Controller::func_load(const QString& filename, Sensor_manager& sm1){
    // CONTROLLER
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        // Errore se non è possibile aprire il file
        qWarning() << "Impossibile aprire il file per la lettura:" << file.errorString();
        return;
    }
    sm1.loadDataFromJson(file);
}

void Controller::printInfoTest(Sensor* s){
    sm->print_sensor_list();
}
