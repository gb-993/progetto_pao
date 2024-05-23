#include "create_sensor_window.h"

CreateSensorWindow::CreateSensorWindow():
    label(new QLabel("Create a sensor:")), textName(new QLineEdit()), menuType(new QComboBox()), textLower(new QComboBox()),
    textUpper(new QComboBox()), menuEnv(new QComboBox()), menuStatusLight(new QComboBox()), menuFilter(new QComboBox()), saveButton(new QPushButton("Save")),
    cancelButton(new QPushButton("Cancel")), mainLayout(new QVBoxLayout()), specificLayout(new QVBoxLayout()) {

    setStyleSheet("background-color: white; color: purple;");
    resize(400, 200);

    textName->setPlaceholderText("Name ...");

    menuEnv->setPlaceholderText("Envrionment ...");
    menuEnv->addItem("Botte");
    menuEnv->addItem("Stanza");

    menuType->setPlaceholderText("Type ...");
    menuType->addItem("Luce");
    menuType->addItem("Filtri cambiati");
    menuType->addItem("Capacità");
    menuType->addItem("Temperatura");
    menuType->addItem("Umidità");

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

    mainLayout->addWidget(saveButton);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);

    setWindowTitle("Crea sensore");

    connect(menuType, SIGNAL(currentIndexChanged(int)), this, SLOT(updateWidgets()));
}

void CreateSensorWindow::updateWidgets() {
    textLower->hide();
    textUpper->hide();
    menuStatusLight->hide();
    menuFilter->hide();

    QString sensorType = menuType->currentText();
    if (sensorType == "Luce") {
        menuStatusLight->setPlaceholderText("Light Status ...");
        menuStatusLight->addItem("0");
        menuStatusLight->addItem("1");
        menuStatusLight->show();
    } else if (sensorType == "Filtri cambiati") {
        menuFilter->setPlaceholderText("Filter Changed ... ");
        for(int i = 0; i <= 3; ++i){
            menuFilter->addItem(QString::number(i));
        }
        menuFilter->show();
    } else if (sensorType == "Temperatura") {
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
    } else if (sensorType == "Umidità"){
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

