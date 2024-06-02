#include "top_layout.h"

TopLayout::TopLayout(): createButton(new QPushButton("Create Sensor")), uploadButton(new QPushButton("Upload Simulation")),
    saveButton(new QPushButton("Save")), buttonsLayout(new QHBoxLayout()),
    uploadWindow(new QFileDialog()){

    setFixedHeight(50);

    // Setto caratteristiche bottoni
    createButton->setStyleSheet("background-color: white; color: #000080; font-size: 17px;");
    createButton->setFixedWidth(200);
    uploadButton->setStyleSheet("background-color: white; color: #000080; font-size: 17px;");
    uploadButton->setFixedWidth(200);
    saveButton->setStyleSheet("background-color: white; color: #000080; font-size: 17px;");
    saveButton->setFixedWidth(200);
    saveButton->setDisabled(true);

    // Aggiungo bottoni al layout
    buttonsLayout->addWidget(createButton);
    buttonsLayout->addWidget(uploadButton);
    buttonsLayout->addWidget(saveButton);
    buttonsLayout->addStretch(); // Per avere i bottoni a sinistra

    setLayout(buttonsLayout);

    disconnect(createButton, &QPushButton::clicked, this, &TopLayout::showCreateWindow);
    disconnect(uploadButton, &QPushButton::clicked, uploadWindow, &QFileDialog::exec);
    connect(createButton, &QPushButton::clicked, this, &TopLayout::showCreateWindow);
    connect(uploadButton, &QPushButton::clicked, uploadWindow, &QFileDialog::exec);
    // apre solo la finestra
    connect(saveButton, &QPushButton::clicked, [=]() {
        QString filePath = QFileDialog::getSaveFileName(uploadWindow, "Salva file", QDir::homePath(), "Tutti i file (*.*)");
        // Qui puoi gestire il percorso del file selezionato
    });
}

void TopLayout::showCreateWindow(){
    emit showCreateWindowSignal();
}

QPushButton* TopLayout::getSaveButton(){
    return saveButton;
}

