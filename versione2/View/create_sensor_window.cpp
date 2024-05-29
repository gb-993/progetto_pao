#include "create_sensor_window.h"

CreateSensorWindow::CreateSensorWindow():
    label(new QLabel("Create a sensor:")), textName(new QLineEdit()), menuType(new QComboBox()), textLower(new QComboBox()),
    textUpper(new QComboBox()), menuEnv(new QComboBox()), menuStatusLight(new QComboBox()), menuFilter(new QComboBox()), createButton(new QPushButton("Create")),
    cancelButton(new QPushButton("Cancel")), mainLayout(new QVBoxLayout()), specificLayout(new QVBoxLayout()) {

    setStyleSheet("background-color: #c2c2a3; color: #000080;");
    resize(400, 200);

    textName->setPlaceholderText("Name ...");

    menuEnv->setPlaceholderText("Environment ...");
    menuEnv->addItem("Tank");
    menuEnv->addItem("Room");

    menuType->setPlaceholderText("Type ...");
    menuType->addItem("Light");
    menuType->addItem("Filter Changed");
    menuType->addItem("Volume");
    menuType->addItem("Temperature");
    menuType->addItem("Humidity");

    // Add widgets to specific layout
    specificLayout->addWidget(textLower);
    specificLayout->addWidget(textUpper);
    specificLayout->addWidget(menuStatusLight);
    specificLayout->addWidget(menuFilter);
    textLower->hide();
    textUpper->hide();
    menuStatusLight->hide();
    menuFilter->hide();

    mainLayout->addWidget(label);
    mainLayout->addWidget(textName);
    mainLayout->addWidget(menuEnv);
    mainLayout->addWidget(menuType);

    // Add specific layout to main layout
    mainLayout->addLayout(specificLayout);

    mainLayout->addWidget(createButton);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);

    setWindowTitle("Create sensor");

    connect(menuType, SIGNAL(currentIndexChanged(int)), this, SLOT(updateWidgets()));
    connect(createButton, &QPushButton::clicked, this, &CreateSensorWindow::createButtonClicked);
}

void CreateSensorWindow::updateWidgets() {
    textLower->hide();
    textUpper->hide();
    menuStatusLight->hide();
    menuFilter->hide();

    QString sensorType = menuType->currentText();
    if (sensorType == "Light") {
        menuStatusLight->setPlaceholderText("Light Status ...");
        menuStatusLight->addItem("0");
        menuStatusLight->addItem("1");
        menuStatusLight->show();
    } else if (sensorType == "Filter Changed") {
        menuFilter->setPlaceholderText("Filter Changed ... ");
        for(int i = 0; i <= 3; ++i){
            menuFilter->addItem(QString::number(i));
        }
        menuFilter->show();
    } else if (sensorType == "Temperature") {
        textUpper->clear();
        textLower->clear();
        textUpper->setPlaceholderText("Max value ...");
        for(float i = 16.0; i <= 18.0; i+=0.3){
            textUpper->addItem(QString::number(i));
        }
        textLower->setPlaceholderText("Min value ...");
        for(float i = 10.0; i <= 12.0; i+=0.3){
            textLower->addItem(QString::number(i));
        }
        textUpper->show();
        textLower->show();
    } else if (sensorType == "Humidity"){
        textUpper->clear();
        textLower->clear();
        textUpper->setPlaceholderText("Max value ...");
        for(float i = 78.0; i <= 80.0; i+=0.2){
            textUpper->addItem(QString::number(i));
        }
        textLower->setPlaceholderText("Min value ...");
        for(float i = 70.0; i <= 72.0; i+=0.2){
            textLower->addItem(QString::number(i));
        }
        textUpper->show();
        textLower->show();
    } else {
        textUpper->clear();
        textUpper->setPlaceholderText("Max value ... ");
        for(float i = 150.0; i <= 500.0; i+=50.0){
            textUpper->addItem(QString::number(i));
        }
        textUpper->show();
    }
}

void CreateSensorWindow::createButtonClicked(){
    emit createButtonClickedSignal();
}

int CreateSensorWindow::getId() const {
    return 3;
}
QString CreateSensorWindow::getName() const {
    return textName->text();
}
QString CreateSensorWindow::getType() const {
    return menuType->currentText();
}
QString CreateSensorWindow::getEnv() const {
    return menuEnv->currentText();
}
int CreateSensorWindow::getFilter() const {
    return menuFilter->currentText().toInt();
}
double CreateSensorWindow::getLower() const {
    return textLower->currentText().toDouble();
}
double CreateSensorWindow::getUpper() const {
    return textUpper->currentText().toDouble();
}
bool CreateSensorWindow::getStatus() const {
    return textLower->currentText().toInt();
}

