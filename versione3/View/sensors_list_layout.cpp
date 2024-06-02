#include "sensors_list_layout.h"

SensorsListLayout::SensorsListLayout() :
    sensorsLabel(new QLabel("Create a sensor or upload a simulation")),
    searchBar(new QLineEdit()),
    layout(new QVBoxLayout()),
    buttonsLayout(new QVBoxLayout())
{
    // Imposta la larghezza fissa
    setFixedWidth(200);

    // Imposta caratteristiche etichetta
    sensorsLabel->setStyleSheet("color: #000080; font-size: 18px;"); // Imposta il colore del testo su blu scuro e la dimensione del carattere a 18px
    sensorsLabel->setWordWrap(true); // Imposta l'avvolgimento del testo
    sensorsLabel->setAlignment(Qt::AlignCenter); // Allinea il testo al centro

    // Imposta caratteristiche searchBar
    searchBar->setPlaceholderText("Search a sensor");
    searchBar->setStyleSheet("background-color: white; color: #000080; font-size: 12px;");

    // Aggiungi gli elementi al layout principale
    layout->addWidget(searchBar, 0, Qt::AlignTop);
    layout->addWidget(sensorsLabel, 0, Qt::AlignTop);
    layout->addLayout(buttonsLayout); // Aggiungi il layout dei bottoni al layout principale
    layout->addStretch(); // Aggiungi uno spazio flessibile in fondo

    setLayout(layout);

    connect(searchBar, &QLineEdit::textChanged, this, &SensorsListLayout::searchTextChanged);
    //connect(button, &QPushButton::clicked, [this, sensor](){ this->showInfo(sensor); });
    //connect(button, &QPushButton::clicked, [this, sensor](){ this->sendSensor(sensor); });
}

void SensorsListLayout::addButton(Sensor* s) {
    sensorsLabel->hide();

    CustomButton* button = new CustomButton(s->getName(),s);
    buttonsList.append(button);
    button->setStyleSheet("background-color: white; color: #000080; font-size: 14px;");
    buttonsLayout->insertWidget(0, button, 0, Qt::AlignTop);

    disconnect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::showInfo);
    connect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::showInfo);
    disconnect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::sendSensor);
    connect(button, &CustomButton::buttonClickedSignal, this, &SensorsListLayout::sendSensor);  //--------

    // TROVARE MODO PER NON FARLO AGGIUNGERE OGNI VOLTA CHE VIENE CHIAMATA ADDBUTTON
    s->addObserver(this);
}

void SensorsListLayout::notify(Sensor& s) {
    qDebug() << "caio";
    for(auto list=buttonsList.begin(); list!=buttonsList.end(); list++){
        qDebug() << "caio2";
        if((*list)->getSensor().getId() == s.getId()){
            qDebug() << "caio3";
            (*list)->setText(s.getName());
        }
    }
}

void SensorsListLayout::showInfo(Sensor* s){
    emit showInfoSignal(s);
}

void SensorsListLayout::sendSensor(Sensor* s){  //--------
    emit sendSensorSignal(s);
}

void SensorsListLayout::searchTextChanged(const QString &text) {
    // La funzione itera attraverso tutti gli elementi presenti nel layout (layout) utilizzando
    // un ciclo for che scorre da 0 fino al numero di elementi nel layout.
    for (int i = 0; i < buttonsLayout->count(); ++i) {
        // Per ogni elemento nel layout, la funzione ottiene il widget corrispondente utilizzando
        // il metodo itemAt(i) del layout. Questo restituisce un puntatore a QWidget
        QWidget *widget = buttonsLayout->itemAt(i)->widget();
        // Utilizzando qobject_cast, la funzione verifica se il widget è di tipo CustomButton.
        // Se è così, viene eseguito il codice all'interno del blocco if.
        if (QPushButton *button = qobject_cast<QPushButton*>(widget)) {
            // Se il widget è un CustomButton, la funzione controlla se il nome del pulsante
            // contiene il testo inserito nella barra di ricerca. Questo controllo viene
            // effettuato tramite il metodo contains della classe QString.
            // Se il nome del pulsante contiene il testo della ricerca (ignorando la differenza
            // tra maiuscole e minuscole), il pulsante viene mostrato utilizzando il metodo show();
            // altrimenti, viene nascosto utilizzando il metodo hide()
            if (button->text().contains(text, Qt::CaseInsensitive)) {
                button->show();
            } else {
                button->hide();
            }
        }
    }
}

