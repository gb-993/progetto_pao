#include "sensors_list_layout.h"
//

SensorsListLayout::SensorsListLayout(): sensorsLabel(new QLabel("Crea uno o più sensori oppure carica una simulazione")), sensorComboBox(new QComboBox()), layout(new QVBoxLayout) {
    // Setto caratteristiche SensorsListLayout
    setStyleSheet("background-color: yellow;");
    setFixedWidth(200);

    // Setto caratteristiche etichetta
    sensorsLabel->setStyleSheet("color: red; font-size: 18px;"); // Imposta il colore del testo su verde e la dimensione del carattere a 16px
    sensorsLabel->setWordWrap(true); // Imposta il avvolgimento del testo
    sensorsLabel->setAlignment(Qt::AlignCenter); // Allinea il testo al centro

    // Setto menu a tendina
    sensorComboBox->setPlaceholderText("Seleziona Sensore");
    sensorComboBox->addItem("Sensore 1");
    sensorComboBox->addItem("Sensore 2");
    sensorComboBox->addItem("Sensore 3");
    // Aggiungi più elementi se necessario

    // Aggiungo elementi al layout
    layout->addWidget(sensorComboBox);
    layout->addWidget(sensorsLabel);
    //layout->addStretch();

    setLayout(layout);
    addButton("Ciao");
    addButton("Gb");
    addButton("Tvb");
    layout->addStretch(); // serve per visualizzarli uno sotto lìaltro ma non troppo distanti..soluzione temporanea

    // Aggiungo icona
    /*QPixmap pixmap("C:/Users/cater/OneDrive/Desktop/Uni/Secondoanno/P2/DocumentiProgetto/test6/icon_searchBar.png"); // Percorso dell'immagine dell'icona
    QIcon icon(pixmap);
    searchBar->addAction(icon, QLineEdit::LeadingPosition); // Imposta l'icona nella posizione di sinistra*/
}

void SensorsListLayout::addButton(QString s) {
    sensorsLabel->hide();

    QPushButton* button = new QPushButton(s);
    layout->addWidget(button);

    setLayout(layout);
}

