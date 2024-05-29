#ifndef CUSTOM_BUTTON_H
#define CUSTOM_BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>

class CustomButton: public QPushButton {
    Q_OBJECT
private:
    QString name;
private slots:
    void showInfo();
signals:
    void showInfoSignal();
public:
    CustomButton(QString, QPushButton* parent = nullptr);
};

#endif // CUSTOM_BUTTON_H
