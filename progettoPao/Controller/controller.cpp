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
    disconnect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::exec);
    disconnect(createsensorwindow, &CreateSensorWindow::createButtonClickedSignal, this, &Controller::createSensor);
    disconnect(sensorslist, &SensorsListLayout::showInfoSignal, this, &Controller::showSensorInfo);
    disconnect(sensorslist, &SensorsListLayout::sendSensorSignal, this, &Controller::getSensor);
    disconnect(option, &SensorOptions::showDeleteWindowSignal, confirmwindow, &ConfirmDeleteWindow::exec);
    disconnect(option, &SensorOptions::showModifyWindowSignal, modifysensorwindow, &ModifySensorWindow::exec);
    disconnect(modifysensorwindow, &ModifySensorWindow::saveButtonClickedSignal, this, &Controller::modifySensor);
    disconnect(option, &SensorOptions::startNewSimulationSignal, this, &Controller::newSimulation);
    disconnect(confirmwindow, &ConfirmDeleteWindow::deleteButtonClickedSignal, this, &Controller::deleteSensor);
    disconnect(top, &TopLayout::showSaveWindowSignal, this, &Controller::openSaveWindow);
    disconnect(top, &TopLayout::showLoadWindowSignal, this, &Controller::openLoadWindow);

    connect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::resetFields);
    connect(top, &TopLayout::showCreateWindowSignal, createsensorwindow, &CreateSensorWindow::exec);
    connect(createsensorwindow, &CreateSensorWindow::createButtonClickedSignal, this, &Controller::createSensor);
    connect(sensorslist, &SensorsListLayout::showInfoSignal, this, &Controller::showSensorInfo);
    connect(sensorslist, &SensorsListLayout::sendSensorSignal, this, &Controller::getSensor);
    connect(option, &SensorOptions::showDeleteWindowSignal, confirmwindow, &ConfirmDeleteWindow::exec);
    connect(option, &SensorOptions::showModifyWindowSignal, modifysensorwindow, &ModifySensorWindow::exec);
    connect(modifysensorwindow, &ModifySensorWindow::saveButtonClickedSignal, this, &Controller::modifySensor);
    connect(option, &SensorOptions::startNewSimulationSignal, this, &Controller::newSimulation);
    connect(confirmwindow, &ConfirmDeleteWindow::deleteButtonClickedSignal, this, &Controller::deleteSensor);
    connect(sensorslist, &SensorsListLayout::sendSensorSignal, this, &Controller::getSensorDelete);
    connect(top, &TopLayout::showSaveWindowSignal, this, &Controller::openSaveWindow);
    connect(top, &TopLayout::showLoadWindowSignal, this, &Controller::openLoadWindow);
}

// crea un sensore in base al tipo selezionato da utente
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
    createsensorwindow->close();
    sensorslist->addButton(sensor);
    top->getSaveButton()->setDisabled(false);
}

// modifica il sensore passato
void Controller::modifySensor(Sensor* s) {
    if(modifysensorwindow->getName() != "")
        s->setName(modifysensorwindow->getName());
    if(modifysensorwindow->getEnv() != "")
        s->setEnv(modifysensorwindow->getEnv());

    visitor = new SensorControllerVisitor(modifysensorwindow->getMenu(), modifysensorwindow->getMenu2());
    s->accept(*visitor);

    modifysensorwindow->close();
}

// elimina il sensore passato
void Controller::deleteSensor(Sensor* s) {
    sm->removeSensor(s);
    delete s;
    s = nullptr;

    confirmwindow->close();
    info->hide();
    option->hide();
    chart->hide();
    singlesensor->getLabel()->show();
    refresh();
}

// chiama la setUpOptions sul sensore passato
void Controller::showSensorInfo(Sensor* s) {
    singlesensor->setUpOptions(s);
}

// chiama la setUpModify sul sensore passato
void Controller::getSensor(Sensor* s) {
    modifysensorwindow->setUpModify(s);
}

// chiama la setUpDelete sul sensore passato
void Controller::getSensorDelete(Sensor* s) {
    confirmwindow->setUpDelete(s);
}

// genera una simulazione per il sensore passato e chiama la setUpCharts sul sensore passato
void Controller::newSimulation(Sensor* s) {
    s->genSimulation();
    chart->setUpChart(s->getSimData());
}

// prende il path da QFileDialog e chiama la funzione func_save(path)
void Controller::openSaveWindow() const {
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save JSON File", "", "JSON Files (*.json);;All Files (*)");
    if (!fileName.isEmpty()) {
        func_save(fileName);
    }
}

// prende il path da QFileDialog e resetta liste e chiama func_load(path)
void Controller::openLoadWindow() {
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open JSON File", "", "JSON Files (*.json);;All Files (*)");
    if (!fileName.isEmpty()) {
        sm->removeAllSensor();
        func_load(fileName);
        hideSingleSensorView();
        top->getSaveButton()->setDisabled(false);
        refresh();
    }
}

// riceve il path e avvia il processo di salvataggio di un file
void Controller::func_save(const QString& filename) const {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Impossibile aprire il file per la scrittura:" << file.errorString();
        return;
    }
    QJsonDocument saveDoc(sm->sensorListToJson());
    file.write(saveDoc.toJson());
    file.close();
}

// riceve il path e avvia il processo di load
void Controller::func_load(const QString& filename){
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Impossibile aprire il file per la lettura:" << file.errorString();
        return;
    }
    sm->loadDataFromJson(file);
}

// aggiorna la view ogni volta che vengono effettuate delle modifiche alla lista di sensori (delete e upload)
void Controller::refresh() {
    sensorslist->clearLayout();
    sensorslist->getButtonsList()->clear();

    QList<Sensor*> sensors = sm->getSensors();

    if(sensors.empty()){
        hideSingleSensorView();
    } else {
        for (auto &one_sensor : sensors) {
            sensorslist->addButton(one_sensor);
        }
    }
}

// nasconde la finestra specifica di un sensore
void Controller::hideSingleSensorView() const {
    sensorslist->getLabel()->show();
    top->getSaveButton()->setDisabled(true);
    info->hide();
    option->hide();
    chart->hide();
    singlesensor->getLabel()->show();
}

