#include "top_layout.h"

TopLayout::TopLayout(): createButton(new QPushButton("Create Sensor")), uploadButton(new QPushButton("Upload Simulation")),
    saveButton(new QPushButton("Save")), buttonsLayout(new QHBoxLayout()){

    setFixedHeight(50);

    createButton->setStyleSheet("background-color: white; color: #000080; font-size: 17px;");
    createButton->setFixedWidth(200);
    uploadButton->setStyleSheet("background-color: white; color: #000080; font-size: 17px;");
    uploadButton->setFixedWidth(200);
    saveButton->setStyleSheet("background-color: white; color: #000080; font-size: 17px;");
    saveButton->setFixedWidth(200);
    saveButton->setDisabled(true);

    buttonsLayout->addWidget(createButton);
    buttonsLayout->addWidget(uploadButton);
    buttonsLayout->addWidget(saveButton);
    buttonsLayout->addStretch();

    setLayout(buttonsLayout);

    disconnect(createButton, &QPushButton::clicked, this, &TopLayout::showCreateWindow);
    disconnect(uploadButton, &QPushButton::clicked, this, &TopLayout::showLoadWindow);
    disconnect(saveButton, &QPushButton::clicked, this, &TopLayout::showSaveWindow);

    connect(createButton, &QPushButton::clicked, this, &TopLayout::showCreateWindow);
    connect(uploadButton, &QPushButton::clicked, this, &TopLayout::showLoadWindow);
    connect(saveButton, &QPushButton::clicked, this, &TopLayout::showSaveWindow);
}

void TopLayout::showCreateWindow(){
    emit showCreateWindowSignal();
}

void TopLayout::showLoadWindow(){
    emit showLoadWindowSignal();
}

void TopLayout::showSaveWindow(){
    emit showSaveWindowSignal();
}

QPushButton* TopLayout::getSaveButton(){
    return saveButton;
}

