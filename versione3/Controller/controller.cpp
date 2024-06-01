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

    mainwindow->showMaximized();

    connect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::resetFields);
    connect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::exec); //questa non si potrebbe spostare da altre parti? non usa &controller come quanrto paramtero
    connect(createsensorwindow, &CreateSensorWindow::createButtonClickedSignal, this, &Controller::createSensor);
    connect(sensorslist, &SensorsListLayout::showInfoSignal, this, &Controller::showSensorInfo);
    connect(sensorslist, &SensorsListLayout::sendSensorSignal, this, &Controller::getSensor);
    //connect(sensorslist, &SensorsListLayout::setModifySignal, this, &Controller::setUpModify); //--------

    /*connect(option, &SensorOptions::showModifyWindowSignal, [=]() {
        modifysensorwindow->setUpModify(sensor);
    });*/

    connect(option, &SensorOptions::showModifyWindowSignal, modifysensorwindow, &ModifySensorWindow::exec);
    // SU QUESTA IL MIO SENGALE DOVREBBE PASSARMI UN SENSORE MA COME FACCIO? VEDI MODIFY SENSOR WINDOW PER CAPIRE DA DOVE ARRIVA IL SEGNALE
    connect(modifysensorwindow, &ModifySensorWindow::saveButtonClickedSignal, this, &Controller::modifySensor);

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
    sensorslist->addButton(sensor);
    top->getSaveButton()->setDisabled(false);
}

void Controller::modifySensor(Sensor* s) {
    s->setName(modifysensorwindow->getName());
    s->setEnv(modifysensorwindow->getEnv());

    // NON VA --> FARE VISITOR
    if(dynamic_cast<Sensor_light*>(s)){
        //s = static_cast<Sensor_light*>(s);
        s->setStatus(modifysensorwindow->getMenu().toInt());
        s->print_sensor();
    }
    modifysensorwindow->close();
}

void Controller::showSensorInfo(Sensor* s) {
    singlesensor->setUpOptions(s);
}
void Controller::getSensor(Sensor* s) { //-------
    modifysensorwindow->setUpModify(s);
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
