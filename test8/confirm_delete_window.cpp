#include "confirm_delete_window.h"

ConfirmDeleteWindow::ConfirmDeleteWindow(): label(new QLabel("Do you want to delete this sensor?")),
    deleteButton(new QPushButton("Yes")), backButton(new QPushButton("No")), layout(new QVBoxLayout()) {

    layout->addWidget(label);
    layout->addWidget(deleteButton);
    layout->addWidget(backButton);

    setLayout(layout);

    setWindowTitle("Delete sensor");
}
