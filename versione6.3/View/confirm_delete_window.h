#ifndef CONFIRM_DELETE_WINDOW_H
#define CONFIRM_DELETE_WINDOW_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include "../Model/sensor.h"
#include "custom_button.h"

class ConfirmDeleteWindow: public QDialog {
    Q_OBJECT
private:
    QLabel *label;
    CustomButton* deleteButton;
    QPushButton* backButton;
    QVBoxLayout* layout;
private slots:
    void deleteButtonClicked(QPointer<Sensor>);
signals:
    void deleteButtonClickedSignal(Sensor*);
public:
    ConfirmDeleteWindow(QDialog* parent = nullptr);
    void setUpDelete(Sensor*);
};

#endif // CONFIRM_DELETE_WINDOW_H
