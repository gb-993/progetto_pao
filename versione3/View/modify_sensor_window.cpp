#include "modify_sensor_window.h"

ModifySensorWindow::ModifySensorWindow(QDialog* parent): QDialog(parent){
    label = new QLabel("Modify sensor: ");
    textName = new QLineEdit();
    textLower = new QLineEdit();
    textUpper = new QLineEdit();
    menuEnv = new QComboBox();
    menuStatusLight = new QComboBox();
    menuFilter = new QComboBox();
    saveButton = new QPushButton("Save");
    cancelButton = new QPushButton("Cancel");
    settingsLayout = new QVBoxLayout();
    mainLayout = new QVBoxLayout();
    buttonLayout = new QVBoxLayout();
    visitor = new SensorModifyVisitor();
    menu = new QComboBox();
    menu2 = new QComboBox();

    setStyleSheet("background-color: #c2c2a3; color: #000080;");
    resize(400, 200);
    setWindowTitle("Modifica sensore");

    textName->setPlaceholderText("Change name");
    menuEnv->setPlaceholderText("Change environment");
    menuEnv->addItem("Tank");
    menuEnv->addItem("Room");

    settingsLayout->addWidget(label);
    settingsLayout->addWidget(textName);
    settingsLayout->addWidget(menuEnv);

    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(settingsLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    // COME FACCIO A PASSARGLI IL SENSORE SE LO RICEVO SOLO SU SETUPMODIFY????
    connect(saveButton, &QPushButton::clicked, this, &ModifySensorWindow::saveButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &QWidget::close);
}

void ModifySensorWindow::setUpModify(Sensor* s) {

    s->accept(*visitor);

    if(menu){
        delete menu;
    }
    if(menu2){
        delete menu2;
    }
    menu = visitor->getMenu();
    menu2 = visitor->getMenu2();

    settingsLayout->addWidget(menu);
    settingsLayout->addWidget(menu2);
}

void ModifySensorWindow::saveButtonClicked(){
    emit saveButtonClickedSignal();
}