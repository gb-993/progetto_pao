#include "controller.h"

Controller::Controller(QObject* parent): QObject(parent) {
    chart = new ChartsLayout();
    info = new InfoLayout();
    option = new SensorOptions();
    singlesensor = new SingleSensorLayout(option, info, chart);
    sensorslist = new SensorsListLayout();
    top = new TopLayout();
    mainwindow = new MainWindow(top, sensorslist, singlesensor);
    createsensorwindow = new CreateSensorWindow();
    modifysensorwindow = new ModifySensorWindow();
    confirmwindow = new ConfirmDeleteWindow();

    sm = new Sensor_manager();

    mainwindow->showMaximized();

    disconnect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::resetFields);
    disconnect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::exec); //questa non si potrebbe spostare da altre parti? non usa &controller come quanrto paramtero
    disconnect(createsensorwindow, &CreateSensorWindow::createButtonClickedSignal, this, &Controller::createSensor);
    disconnect(sensorslist, &SensorsListLayout::showInfoSignal, this, &Controller::showSensorInfo);
    disconnect(sensorslist, &SensorsListLayout::sendSensorSignal, this, &Controller::getSensor);
    disconnect(option, &SensorOptions::showDeleteWindowSignal, confirmwindow, &ConfirmDeleteWindow::exec);
    disconnect(option, &SensorOptions::showModifyWindowSignal, modifysensorwindow, &ModifySensorWindow::exec);
    disconnect(modifysensorwindow, &ModifySensorWindow::saveButtonClickedSignal, this, &Controller::modifySensor);
    disconnect(option, &SensorOptions::startNewSimulationSignal, this, &Controller::newSimulation);
    disconnect(confirmwindow, &ConfirmDeleteWindow::deleteButtonClickedSignal, this, &Controller::deleteSensor);
    disconnect(sensorslist, &SensorsListLayout::sendSensorSignal, this, &Controller::getSensorDelete);

    connect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::resetFields);
    connect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::exec); //questa non si potrebbe spostare da altre parti? non usa &controller come quanrto paramtero
    connect(createsensorwindow, &CreateSensorWindow::createButtonClickedSignal, this, &Controller::createSensor);
    connect(sensorslist, &SensorsListLayout::showInfoSignal, this, &Controller::showSensorInfo);
    connect(sensorslist, &SensorsListLayout::sendSensorSignal, this, &Controller::getSensor);
    connect(option, &SensorOptions::showDeleteWindowSignal, confirmwindow, &ConfirmDeleteWindow::exec);
    connect(option, &SensorOptions::showModifyWindowSignal, modifysensorwindow, &ModifySensorWindow::exec);
    connect(modifysensorwindow, &ModifySensorWindow::saveButtonClickedSignal, this, &Controller::modifySensor);
    connect(option, &SensorOptions::startNewSimulationSignal, this, &Controller::newSimulation);
    connect(confirmwindow, &ConfirmDeleteWindow::deleteButtonClickedSignal, this, &Controller::deleteSensor);
    connect(sensorslist, &SensorsListLayout::sendSensorSignal, this, &Controller::getSensorDelete);
}

void Controller::createSensor() {
    QString name = createsensorwindow->getName();
    QString env = createsensorwindow->getEnv();
    QString type = createsensorwindow->getType();
    Sensor* sensor;
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
    sm->addSensor(sensor);
    sm->print_sensor_list();
    refresh(sm, sensorslist);
    createsensorwindow->close();
    //sensorslist->addButton(sensor);
    top->getSaveButton()->setDisabled(false);
}

void Controller::modifySensor(Sensor* s) {
    if(modifysensorwindow->getName() != "")
        s->setName(modifysensorwindow->getName());
    if(modifysensorwindow->getEnv() != "")
        s->setEnv(modifysensorwindow->getEnv());

    visitor = new SensorControllerVisitor(modifysensorwindow->getMenu(), modifysensorwindow->getMenu2());
    s->accept(*visitor);

    modifysensorwindow->close();
}

void Controller::deleteSensor(Sensor* s){
    /*
    for (Sensor* sensor : sm->getSensors()) {
        if (sensor->getId() == s->getId()) {
            sm->print_sensor_list();
            //sm->getSensors().remove(; //basta questo???
            sm->print_sensor_list();
            confirmwindow->close();
            refresh(sm,sensorslist);
        }
    }
*/
}

void Controller::showSensorInfo(Sensor* s) {
    singlesensor->setUpOptions(s);
}

void Controller::getSensor(Sensor* s) {
    modifysensorwindow->setUpModify(s);
}

void Controller::getSensorDelete(Sensor* s) {
    confirmwindow->setUpDelete(s);
}

void Controller::newSimulation(Sensor* s) {
    s->genSimulation();
    chart->setUpChart(s->getSimData());
}

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

void Controller::refresh(Sensor_manager* list, SensorsListLayout* sl) {
    sl->clearLayout(sl->getLayout());
    clearButtonsList(sl->getButtonsList());

    QList<Sensor*> sensors = list->getSensors();
    for (auto &one_sensor : sensors) {
        sl->addButton(one_sensor);
    }
}

void Controller::clearButtonsList(QList<CustomButton*> bl) {
    bl.clear();
}
