#include "confirm_delete_window.h"

ConfirmDeleteWindow::ConfirmDeleteWindow(): label(new QLabel("Do you want to delete this sensor?")),
    deleteButton(new CustomButton("Yes", nullptr)), backButton(new QPushButton("No")), layout(new QVBoxLayout()) {

    setStyleSheet("background-color: #c2c2a3; color: #000080;");

    layout->addWidget(label);
    layout->addWidget(deleteButton);
    layout->addWidget(backButton);

    setLayout(layout);

    setWindowTitle("Delete sensor");

    disconnect(backButton, &QPushButton::clicked, this, &QWidget::close);
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);
}

void ConfirmDeleteWindow::setUpDelete(Sensor* s) {
    deleteButton->setSensor(s);

    disconnect(deleteButton, &CustomButton::buttonClickedSignal, this, &ConfirmDeleteWindow::deleteButtonClicked);
    connect(deleteButton, &CustomButton::buttonClickedSignal, this, &ConfirmDeleteWindow::deleteButtonClicked);
}

void ConfirmDeleteWindow::deleteButtonClicked(Sensor* s) {
    emit deleteButtonClickedSignal(s);
}
