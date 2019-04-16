#ifndef PERSON_H
#define PERSON_H

#include <QStringList>
#include <QDate>

class Person
{
public:
    Person() : lebensnummer_(0) {}
    Person(const QString &name, const QString &zuname, const QDate &geburtsdatum, const unsigned lebensnummer, const QString &egk, const QString &auftrag, const unsigned index);

    const QString& vorname() const { return vorname_; }
    void setVorname(const QString &vorname) { vorname_ = vorname; }
    const QString& zuname() const { return  zuname_; }
    void setZuname(const QString &zuname) { zuname_ = zuname; }
    const QDate& geburtsdatum() const {return geburtsdatum_; }
    void setGeburtsdatum(const QDate &date) { geburtsdatum_ = date; }
    unsigned lebensnummer() const { return lebensnummer_; }
    void setLebensnummer(const unsigned lebensnummer) { lebensnummer_ = lebensnummer; }
    QString egk() const { return egk_; }
    void setEgk(const QString &egk) { egk_ = egk; }
    QString auftragsNr() const { return auftragsNr_; }
    void setAuftragsNr(const QString &auftragsNr) { auftragsNr_ = auftragsNr; }
    unsigned index() const { return index_; }
    void setIndex(const unsigned index) { index_ = index; }

    static Person randomPerson();
    static QList<Person> randomPersonList(const unsigned anzahl);
    static QString randomAuftragNummer();
    static QString RandomEgkNummer();

private:
    QString vorname_;
    QString zuname_;
    QDate geburtsdatum_;
    unsigned lebensnummer_ = 0;
    QString egk_;
    QString auftragsNr_;
    unsigned index_;
    static QStringList vornameListe_;
    static QStringList zunameListe_;
};

#endif // PERSON_H
