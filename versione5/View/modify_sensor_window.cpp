#include "modify_sensor_window.h"

ModifySensorWindow::ModifySensorWindow(QDialog* parent): QDialog(parent){
    label = new QLabel("Modify sensor: ");
    textName = new QLineEdit();
    menuEnv = new QComboBox();
    saveButton = new CustomButton("Save");
    cancelButton = new QPushButton("Cancel");
    settingsLayout = new QVBoxLayout();
    mainLayout = new QVBoxLayout();
    buttonLayout = new QVBoxLayout();
    visitor = new SensorModifyVisitor();
    menu = new QComboBox();
    menu2 = new QComboBox();

    setStyleSheet("background-color: #c2c2a3; color: #000080;");
    resize(400, 200);
    setWindowTitle("Modify sensor");

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

    disconnect(cancelButton, &QPushButton::clicked, this, &QWidget::close);
    disconnect(saveButton, &CustomButton::clicked, this, &ModifySensorWindow::cleanFields);

    connect(saveButton, &CustomButton::clicked, this, &ModifySensorWindow::cleanFields);
    connect(cancelButton, &QPushButton::clicked, this, &QWidget::close);
}

void ModifySensorWindow::setUpModify(Sensor* s) {
    saveButton->setSensor(s);

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

    disconnect(saveButton, &CustomButton::buttonClickedSignal, this, &ModifySensorWindow::saveButtonClicked);
    connect(saveButton, &CustomButton::buttonClickedSignal, this, &ModifySensorWindow::saveButtonClicked);
}

void ModifySensorWindow::cleanFields() {
    textName->clear();
    menuEnv->setCurrentIndex(-1);
    menu->setCurrentIndex(-1);
    menu2->setCurrentIndex(-1);
}

void ModifySensorWindow::saveButtonClicked(Sensor* s){
    emit saveButtonClickedSignal(s);
}

QString ModifySensorWindow::getName() const {
    return textName->text();
}
QString ModifySensorWindow::getEnv() const {
    return menuEnv->currentText();
}
QString ModifySensorWindow::getMenu() const {
    return menu->currentText();
}
QString ModifySensorWindow::getMenu2() const {
    return menu2->currentText();
}
