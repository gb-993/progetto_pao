#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), general_window(new GeneralWindow()) {
    //GeneralWindow* general_window = new GeneralWindow();
    setCentralWidget(general_window);

    ModifySensorWindow* modifica = new ModifySensorWindow();
    modifica->show(); // se voglio che quando si apra l'esecuzione di 'blocchi' finchè l'utente non ha finito scrivo ->exec()

    ConfirmDeleteWindow* del = new ConfirmDeleteWindow();
    del->show(); // stesso discorso di prima con exec()

    CreateSensorWindow* crea = new CreateSensorWindow();
    crea -> show();
}

MainWindow::~MainWindow() {}

