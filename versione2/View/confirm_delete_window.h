#ifndef CONFIRM_DELETE_WINDOW_H
#define CONFIRM_DELETE_WINDOW_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class ConfirmDeleteWindow: public QDialog {
    Q_OBJECT
private:
    QLabel *label;
    QPushButton* deleteButton;
    QPushButton* backButton;
    QVBoxLayout* layout;
public:
    ConfirmDeleteWindow();
};

#endif // CONFIRM_DELETE_WINDOW_H
