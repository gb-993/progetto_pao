#include "confirm_delete_window.h"

ConfirmDeleteWindow::ConfirmDeleteWindow(QDialog* parent): QDialog(parent) {

    label = new QLabel("Do you want to delete this sensor?");
    deleteButton = new CustomButton(QIcon(":/icons/check.svg"), "  Yes");
    backButton = new QPushButton(QIcon(":/icons/times.svg"), "  No");
    layout = new QVBoxLayout();

    setStyleSheet("background-color: #c2c2a3; color: #000080;");

    layout->addWidget(label);
    layout->addWidget(deleteButton);
    layout->addWidget(backButton);

    setLayout(layout);

    setWindowTitle("Delete sensor");

    disconnect(backButton, &QPushButton::clicked, this, &QWidget::close);
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);
}

// setUp della finestra di conferma eliminazione di un sensore
void ConfirmDeleteWindow::setUpDelete(Sensor* s) {
    deleteButton->setSensor(s);

    disconnect(deleteButton, &CustomButton::buttonClickedSignal, this, &ConfirmDeleteWindow::deleteButtonClicked);
    connect(deleteButton, &CustomButton::buttonClickedSignal, this, &ConfirmDeleteWindow::deleteButtonClicked);
}

// emette segnale per eliminare il sensore
void ConfirmDeleteWindow::deleteButtonClicked(QPointer<Sensor> s) {
    emit deleteButtonClickedSignal(s);
}
