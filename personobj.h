#ifndef PERSONOBJ_H
#define PERSONOBJ_H

#include "person.h"
#include <QObject>
#include <QStringList>

class PersonObj : public QObject, public Person
{
    Q_OBJECT
    Q_PROPERTY(QString vorname READ vorname WRITE setVorname)
    Q_PROPERTY(QString zuname READ zuname WRITE setZuname)
    Q_PROPERTY(QDate geburtsdatum READ geburtsdatum WRITE setGeburtsdatum)
    Q_PROPERTY(unsigned lebensnummer READ lebensnummer WRITE setLebensnummer)

public:
    explicit PersonObj(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PERSONOBJ_H
