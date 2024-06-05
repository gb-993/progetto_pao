#ifndef CREATE_SENSOR_WINDOW_H
#define CREATE_SENSOR_WINDOW_H

#include <QDialog>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class CreateSensorWindow: public QDialog {
    Q_OBJECT
private:
    QLabel *label;
    QLineEdit *textName;
    QComboBox *menuType;
    QComboBox *textLower;
    QComboBox *textUpper;
    QComboBox *menuEnv;
    QComboBox *menuStatusLight;
    QComboBox *menuFilter;
    QPushButton *createButton;
    QPushButton *cancelButton;
    QVBoxLayout *mainLayout;
    QVBoxLayout* specificLayout;
private slots:
    void updateWidgets();
    void createButtonClicked();
    void validateFields();
signals:
    void createButtonClickedSignal();
public:
    CreateSensorWindow();
    QString getName() const;
    QString getType() const;
    QString getEnv() const;
    int getFilter() const;
    double getLower() const;
    double getUpper() const;
    bool getStatus() const;
public slots:
    void resetFields();
};

#endif // CREATE_SENSOR_WINDOW_H
