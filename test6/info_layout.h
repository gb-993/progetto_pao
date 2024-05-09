#ifndef INFO_LAYOUT_H
#define INFO_LAYOUT_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "sensor.h"

class InfoLayout: public QWidget {
private:
    QLabel* label1;
    QLabel* label2;
    QLabel* label3;
    QHBoxLayout* riga1;
    QHBoxLayout* riga2;
    QHBoxLayout* riga3;
    QVBoxLayout* layout;
public:
    InfoLayout();
};

#endif // INFO_LAYOUT_H
