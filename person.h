#ifndef PERSON_H
#define PERSON_H

#include <QStringList>
#include <QDate>

class Person
{
public:
    Person() : lebensnummer_(0) {}
    Person(const QString &name, const QString &zuname, const QDate &geburtsdatum, const unsigned lebensnummer);

    const QString& vorname() const { return vorname_; }
    void setVorname(const QString &vorname) { vorname_ = vorname; }
    const QString& zuname() const { return  zuname_; }
    void setZuname(const QString &zuname) { zuname_ = zuname; }
    const QDate& geburtsdatum() const {return geburtsdatum_; }
    void setGeburtsdatum(const QDate &date) { geburtsdatum_ = date; }
    unsigned lebensnummer() const { return lebensnummer_; }
    void setLebensnummer(const unsigned lebensnummer) { lebensnummer_ = lebensnummer; }

    static Person randomPerson();
    static QList<Person> randomPersonList(const unsigned anzahl);
    static unsigned randomAuftragNummer();
    static QString RandomEgkNummer();

    static QStringList header();
    static void setHeader(const QStringList &header);

private:
    QString vorname_;
    QString zuname_;
    QDate geburtsdatum_;
    unsigned lebensnummer_ = 0;
    static QStringList vornameListe_;
    static QStringList zunameListe_;
    static QStringList m_header;
};

#endif // PERSON_H
