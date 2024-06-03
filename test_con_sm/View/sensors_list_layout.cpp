#include "sensors_list_layout.h"

SensorsListLayout::SensorsListLayout() :

    sensorsLabel(new QLabel("Create a sensor or upload a simulation")),
    searchBar(new QLineEdit()),
    layout(new QVBoxLayout),
    buttonsLayout(new QVBoxLayout) // Layout per i bottoni
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
}

// funzione da chiamare per ogni elemento di sensorManager
void SensorsListLayout::addButton(Sensor* s, QList<CustomButton>* buttonList) {

    sensorsLabel->hide();

    CustomButton* button = new CustomButton(s);
    buttonList->push_back(button*);

    connect(button, &CustomButton::showInfoSignal, [=]() { callToController(s); });

}


void SensorsListLayout::addButtonToLayout(QList<CustomButton*>* buttonList) {
    for(int i=0; i < buttonList->length(); ++i) {

        buttonList[i].setStyleSheet("background-color: white; color: #000080; font-size: 14px;");
        buttonsLayout->insertWidget(0, buttonList[i], 0, Qt::AlignTop);
    }
}

void SensorsListLayout::callToController(Sensor *s){
    emit callToControllerSignal(s);
}

QVBoxLayout* SensorsListLayout::getLayout() const {
    return layout*;
}

QList<CustomButton>* SensorsListLayout::getButtonList() const {
    return buttonList*;
}

// svuota layout
void SensorsListLayout::clearLayout(QVBoxLayout * layout) {
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
    }delete item;
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
        if (CustomButton *button = qobject_cast<CustomButton*>(widget)) {
            // Se il widget è un CustomButton, la funzione controlla se il nome del pulsante
            // contiene il testo inserito nella barra di ricerca. Questo controllo viene
            // effettuato tramite il metodo contains della classe QString.
            // Se il nome del pulsante contiene il testo della ricerca (ignorando la differenza
            // tra maiuscole e minuscole), il pulsante viene mostrato utilizzando il metodo show();
            // altrimenti, viene nascosto utilizzando il metodo hide()
            if (button->getName().contains(text, Qt::CaseInsensitive)) {
                button->show();
            } else {
                button->hide();
            }
        }
    }
}


