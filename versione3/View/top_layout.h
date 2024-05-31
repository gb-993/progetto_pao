#ifndef TOP_LAYOUT_H
#define TOP_LAYOUT_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFileDialog>
#include "create_sensor_window.h"

class TopLayout: public QWidget {
    Q_OBJECT
private:
    QPushButton *createButton;
    QPushButton *uploadButton;
    QPushButton *saveButton;
    QHBoxLayout *buttonsLayout;
    CreateSensorWindow* createWindow;
    QFileDialog* uploadWindow;
private slots:
    void showCreateWindow();
signals:
    void showCreateWindowSignal();
public:
    TopLayout();
};

#endif // TOP_LAYOUT_H
