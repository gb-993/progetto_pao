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
private slots:
    void showCreateWindow();
    void showLoadWindow();
    void showSaveWindow();
signals:
    void showCreateWindowSignal();
    void showLoadWindowSignal();
    void showSaveWindowSignal();
public:
    TopLayout(QWidget* parent = nullptr);
    QPushButton* getSaveButton() const ;
};

#endif // TOP_LAYOUT_H
