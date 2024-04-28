/*
#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include <QObject>
#include <QJsonDocument>

class JsonSerializer : public QObject
{
    Q_OBJECT

public:
    JsonSerializer(QObject *parent = nullptr);
    // Funzioni per la serializzazione e deserializzazione dei dati
    void saveToJson(const QString &filename, const QJsonObject &jsonObject);
    QJsonObject loadFromJson(const QString &filename);
};

#endif // JSONSERIALIZER_H

*/
