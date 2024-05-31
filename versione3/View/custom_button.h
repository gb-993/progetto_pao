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
    void setUpModify();
signals:
    void showInfoSignal();
    void setUpModifySignal();
public:
    CustomButton(QString, QPushButton* parent = nullptr);
    QString getName() const;
};

#endif // CUSTOM_BUTTON_H
