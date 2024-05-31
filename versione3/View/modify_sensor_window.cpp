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
    mainLayout = new QVBoxLayout();
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

    mainLayout->addWidget(label);
    mainLayout->addWidget(textName);
    mainLayout->addWidget(menuEnv);

    //mainLayout->addWidget(menu);
    //mainLayout->addWidget(menu2);
    mainLayout->addWidget(saveButton);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);

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

    mainLayout->addWidget(menu);
    mainLayout->addWidget(menu2);
}
