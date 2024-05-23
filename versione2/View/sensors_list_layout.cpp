#include "sensors_list_layout.h"
//

SensorsListLayout::SensorsListLayout(): sensorsLabel(new QLabel("Create a sensor or upload a simulation")), searchBar(new QLineEdit()), layout(new QVBoxLayout) {
    // Setto caratteristiche SensorsListLayout
    setFixedWidth(200);

    // Setto caratteristiche etichetta
    sensorsLabel->setStyleSheet("color: #000080; font-size: 18px;"); // Imposta il colore del testo su verde e la dimensione del carattere a 16px
    sensorsLabel->setWordWrap(true); // Imposta il avvolgimento del testo
    sensorsLabel->setAlignment(Qt::AlignCenter); // Allinea il testo al centro

    // Setto menu a tendina
    searchBar->setPlaceholderText("Select a sensor");
    searchBar->setStyleSheet("background-color: white; color: #000080; font-size: 12px;");

    // Aggiungi più elementi se necessario

    // Aggiungo elementi al layout
    layout->addWidget(searchBar);
    layout->addWidget(sensorsLabel);
    //layout->addStretch();

    setLayout(layout);
    addButton("Ciao");
    addButton("Cb");
    addButton("Tvb");
    layout->addStretch(); // serve per visualizzarli uno sotto lìaltro ma non troppo distanti..soluzione temporanea

    connect(searchBar, &QLineEdit::textChanged, this, &SensorsListLayout::searchTextChanged);
    // Aggiungo icona
    /*QPixmap pixmap("C:/Users/cater/OneDrive/Desktop/Uni/Secondoanno/P2/DocumentiProgetto/test6/icon_searchBar.png"); // Percorso dell'immagine dell'icona
    QIcon icon(pixmap);
    searchBar->addAction(icon, QLineEdit::LeadingPosition); // Imposta l'icona nella posizione di sinistra*/
}

void SensorsListLayout::addButton(QString s) {
    sensorsLabel->hide();

    QPushButton* button = new QPushButton(s);
    button->setStyleSheet("background-color: white; color: #000080; font-size: 14px;");
    layout->addWidget(button);

    setLayout(layout);
}

void SensorsListLayout::searchTextChanged(const QString &text) {
    // La funzione itera attraverso tutti gli elementi presenti nel layout (layout) utilizzando
    // un ciclo for che scorre da 0 fino al numero di elementi nel layout.
    for (int i = 0; i < layout->count(); ++i) {
        // Per ogni elemento nel layout, la funzione ottiene il widget corrispondente utilizzando
        // il metodo itemAt(i) del layout. Questo restituisce un puntatore a QWidget
        QWidget *widget = layout->itemAt(i)->widget();
        // Utilizzando qobject_cast, la funzione verifica se il widget è di tipo QPushButton.
        // Se è così, viene eseguito il codice all'interno del blocco if.
        if (QPushButton *button = qobject_cast<QPushButton*>(widget)) {
            // Se il widget è un QPushButton, la funzione controlla se il testo del pulsante
            // contiene il testo inserito nella barra di ricerca. Questo controllo viene
            // effettuato tramite il metodo contains della classe QString.
            // Se il testo del pulsante contiene il testo della ricerca (ignorando la differenza
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

