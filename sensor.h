// MODEL

#ifndef SENSOR_H
#define SENSOR_H

#include <QString>
#include <QList>
#include <QPointF>
#include <QWidget>
#include <QDebug>
#include <QRandomGenerator>

class Sensor: public QWidget {
    Q_OBJECT
private:
    QString name;
    QString type;
    // contiene i dati della simulazione (ogni elemento sarà una coppia di coordinate cartesiane per il grafico)
    // in teria QPointF si può usare per salvare coordinate cartesiane -> testato
    QList<QPointF> simulationData;
    int lower;
    int upper;
public:
    Sensor(QString n ="default", QString t ="default", int l =10, int u =20);
    // il costruttore si potrebbe personalizzare in modo che se non inserisci il nome ne mette lui
    // uno di default a partire dal tipo, ad es:
    // type: temperatura
    // nome: temperatura_sensore_1
    // nome: temperatura_sensore_2 se ne creo un altro e così via...
    //Sensor(const QString& name="null", const QString& type="null");
    // utili se voglio modificare sensori
    void setName(const QString&);
    void setType(const QString&);
    void setSimulation(); //AGGIUNTA IO
    // metodi get
    QString getName() const;
    QString getType() const;
    // utile quando serializzo la simulazione:
    // posso sapere se questo sensore ha dei dati-simulazione da salvare oppure no
    bool has_simulation_data() const;
    void print_sensor() const;

    virtual ~Sensor() {}
};


#endif // SENSOR_H
