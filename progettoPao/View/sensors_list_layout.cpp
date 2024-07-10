#include "sensors_list_layout.h"

SensorsListLayout::SensorsListLayout(QWidget* parent): QWidget(parent) {
    sensorsLabel = new QLabel("Create a sensor or upload a simulation");
    searchBar = new QLineEdit();
    layout = new QVBoxLayout();
    buttonsLayout = new QVBoxLayout();
    setFixedWidth(200);

    sensorsLabel->setStyleSheet("color: #000080; font-size: 18px;");
    sensorsLabel->setWordWrap(true);
    sensorsLabel->setAlignment(Qt::AlignCenter);

    searchBar->setClearButtonEnabled(true);
    QAction *iconAction = new QAction();
    QIcon icon(":/icons/search.svg");
    iconAction->setIcon(icon);
    searchBar->addAction(iconAction,QLineEdit::LeadingPosition);
    searchBar->setPlaceholderText("Search a sensor");
    searchBar->setStyleSheet("background-color: white; color: #000080; font-size: 12px;");

    layout->addWidget(searchBar, 0, Qt::AlignTop);
    layout->addWidget(sensorsLabel, 0, Qt::AlignTop);
    layout->addLayout(buttonsLayout);
    layout->addStretch();

    setLayout(layout);

    disconnect(searchBar, &QLineEdit::textChanged, this, &SensorsListLayout::searchTextChanged);
    connect(searchBar, &QLineEdit::textChanged, this, &SensorsListLayout::searchTextChanged);
}

// aggiunge un CustomButton al layout e alla buttonsList; aggiunge this come osservatore del sensore passato
void SensorsListLayout::addButton(Sensor* s) {
    sensorsLabel->hide();
    QIcon *icon = nullptr;
    QString type = s->getType();
    if (type == "Temperature") {
        icon = new QIcon(":/icons/temp.svg");
    } else if (type == "Humidity") {
        icon = new QIcon(":/icons/humidity.svg");
    } else if (type == "Light") {
        icon = new QIcon(":/icons/light.svg");
    } else if (type == "Filter Changed") {
        icon = new QIcon(":/icons/filter.svg");
    } else if (type == "Volume") {
        icon = new QIcon(":/icons/glass.svg");
    }

    CustomButton* button = nullptr;
    if (icon) {
        button = new CustomButton(*icon, "  " + s->getName());
    } else {
        button = new CustomButton(s->getName());
    }
    if(button == nullptr) {
        return;
    }
    button->setSensor(s);
    buttonsList.append(button);
    button->setStyleSheet("background-color: white; color: #000080; font-size: 14px;");

    buttonsLayout->insertWidget(0, button, 0, Qt::AlignTop);

    disconnect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::showInfo);
    disconnect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::sendSensor);

    connect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::showInfo);
    connect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::sendSensor);

    s->addObserver(this);
}

// override del metodo notify che aggiorna il nome del CustomButton quando viene modificato
void SensorsListLayout::notify(Sensor& s) {
    for(auto list=buttonsList.begin(); list!=buttonsList.end(); list++){
        if((*list)->getSensor()->getId() == s.getId()){
            (*list)->setText("  "+s.getName());
            break;
        }
    }
}

// emette segnale per mostrare le info
void SensorsListLayout::showInfo(QPointer<Sensor> s){
    emit showInfoSignal(s);
}

// emette segnale per inviare il sensore
void SensorsListLayout::sendSensor(QPointer<Sensor> s){
    emit sendSensorSignal(s);
}

// ricerca CustomButton in base al loro nome
void SensorsListLayout::searchTextChanged(const QString &text) {
    for (int i = 0; i < buttonsLayout->count(); ++i) {
        QWidget *widget = buttonsLayout->itemAt(i)->widget();
        if (QPushButton *button = qobject_cast<QPushButton*>(widget)) {
            if (button->text().contains(text, Qt::CaseInsensitive)) {
                button->show();
            } else {
                button->hide();
            }
        }
    }
}

// pulisce il layout eliminando tutti i CustomButton presenti in buttonsLayout
void SensorsListLayout::clearLayout() {
    QLayoutItem* item;
    while((item = buttonsLayout->takeAt(0)) != nullptr) {
        if(QWidget* widget = item->widget()) {
            if(qobject_cast<CustomButton*>(widget)) {
                buttonsLayout->removeWidget(widget);
                delete widget;
                widget = nullptr;
            }
        }
        delete item;
        item = nullptr;
    }
}

// ritorna la buttonsList
QList<CustomButton*>* SensorsListLayout::getButtonsList() {
    return &buttonsList;
}

// ritorna la sensorsLabel
QLabel* SensorsListLayout::getLabel() const {
    return sensorsLabel;
}

// rimuove il bottone passato dalla buttonsList
void SensorsListLayout::removeOneButton(CustomButton* b) {
    buttonsList.removeOne(b);
}
