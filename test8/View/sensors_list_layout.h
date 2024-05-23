#ifndef SENSORS_LIST_LAYOUT_H
#define SENSORS_LIST_LAYOUT_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

class SensorsListLayout: public QWidget {
    Q_OBJECT
private:
    QLabel *sensorsLabel;
    QLineEdit *searchBar;
    QVBoxLayout *layout;
public:
    SensorsListLayout();
    void addButton(QString);
private slots:
    void searchTextChanged(const QString&);
};

#endif // SENSORS_LIST_LAYOUT_H
