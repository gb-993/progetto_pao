#ifndef TOP_LAYOUT_H
#define TOP_LAYOUT_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class TopLayout: public QWidget {
    Q_OBJECT
private:
    QPushButton *createButton;
    QPushButton *uploadButton;
    QPushButton *saveButton;
    QHBoxLayout *buttonsLayout;
public:
    TopLayout();
};

#endif // TOP_LAYOUT_H
