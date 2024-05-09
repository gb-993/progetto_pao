#include "top_layout.h"

TopLayout::TopLayout(): createButton(new QPushButton("Create Sensor")), uploadButton(new QPushButton("Upload Simulation")), saveButton(new QPushButton("Save")),buttonsLayout(new QHBoxLayout()) {
    // Setto caratteristiche TopLayout
    setStyleSheet("background-color: green;");
    setFixedHeight(50);

    // Setto caratteristiche bottoni
    createButton->setStyleSheet("background-color: white; color: green; font-size: 17px;");
    createButton->setFixedWidth(200);
    uploadButton->setStyleSheet("background-color: white; color: green; font-size: 17px;");
    uploadButton->setFixedWidth(200);
    saveButton->setStyleSheet("background-color: white; color: green; font-size: 17px;");
    saveButton->setFixedWidth(200);
    saveButton->setDisabled(true);

    // Aggiungo bottoni al layout
    buttonsLayout->addWidget(createButton);
    buttonsLayout->addWidget(uploadButton);
    buttonsLayout->addWidget(saveButton);
    buttonsLayout->addStretch(); // Per avere i bottoni a sinistra

    setLayout(buttonsLayout);
}
