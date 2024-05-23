#include "modify_sensor_window.h"

ModifySensorWindow::ModifySensorWindow():
    label(new QLabel("Modifica le informazioni del sensore:")), textName(new QLineEdit()), textLower(new QLineEdit()),
    textUpper(new QLineEdit()), menuEnv(new QComboBox()), menuStatusLight(new QComboBox()), menuFilter(new QComboBox()), saveButton(new QPushButton("Salva")),
    cancelButton(new QPushButton("Annulla")), mainLayout(new QVBoxLayout()), visitor(new SensorModifyVisitor()) {

    setStyleSheet("background-color: white; color: grey;");
    resize(400, 200);

    Sensor* s = new Sensor_humidity(); // POI VOGLIO CHE ME LO PASSINO NEL COSTRUTTORE??? BOHHH

    textName->setPlaceholderText("Actual name: " + s->getName());

    menuEnv->setPlaceholderText("Actual environment: " + s->getEnv());
    menuEnv->addItem("Tank");
    menuEnv->addItem("Room");

    mainLayout->addWidget(label);
    mainLayout->addWidget(textName);
    mainLayout->addWidget(menuEnv);

     // da aggiugnere ai membti
    s->accept(*visitor);

    mainLayout->addWidget(visitor->getMenu());
    mainLayout->addWidget(visitor->getMenu2());
    mainLayout->addWidget(saveButton);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);

    setWindowTitle("Modifica sensore");
}
