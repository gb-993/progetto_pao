#ifndef CONFIRM_DELETE_WINDOW_H
#define CONFIRM_DELETE_WINDOW_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "custom_button.h"

class ConfirmDeleteWindow: public QDialog {
    Q_OBJECT
private:
    QLabel *label;
    CustomButton* deleteButton;
    QPushButton* backButton;
    QVBoxLayout* layout;
private slots:
    void deleteButtonClicked(Sensor*);
signals:
    void deleteButtonClickedSignal(Sensor*);
public:
    ConfirmDeleteWindow();
    void setUpDelete(Sensor* s);
};

#endif // CONFIRM_DELETE_WINDOW_H
