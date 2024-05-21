#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtCharts>
#include <QLineSeries>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget* window;
    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;

};

#endif // MAINWINDOW_H
