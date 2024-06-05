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
private slots:
    void showCreateWindow();
    void showLoadWindow();
    void showSaveWindow();
signals:
    void showCreateWindowSignal();
    void showLoadWindowSignal();
    void showSaveWindowSignal();
public:
    TopLayout();
    QPushButton* getSaveButton();
};

#endif // TOP_LAYOUT_H
