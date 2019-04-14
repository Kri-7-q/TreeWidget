#include "person.h"
#include <QRandomGenerator>

QStringList Person::vornameListe_ = QStringList() << "Horst" << "Martin" << "Klaus" << "Heinz" << "Fritz"
                                                  << "Thomas" << "Julia" << "Sabine" << "Tanja" << "Simone";
QStringList Person::zunameListe_ = QStringList() << "Meier" << "Hunz" << "Kunz" << "Siedler" << "Gibbs"
                                                 << "Ermann" << "Lunz" << "Hinterhuber" << "Wernersen";
QStringList Person::m_header = QStringList() << "Vorname" << "Zuanme" << "Lebensnummer" << "Geburtsdatum";

//! Konstruktor
Person::Person(const QString &name, const QString &zuname, const QDate &geburtsdatum, const unsigned lebensnummer)
    : vorname_(name)
    , zuname_(zuname)
    , geburtsdatum_(geburtsdatum)
    , lebensnummer_(lebensnummer)
{

}

//! Erzeugt eine Person per Zufallsgenerator.
Person Person::randomPerson()
{
    int seed = QRandomGenerator::global()->generate();
    QRandomGenerator rnd(seed);
    int indexVorname = rnd.generate() % vornameListe_.size();
    int indexZuname = rnd.generate() % zunameListe_.size();
    int tag = rnd.generate() % 28 + 1;
    int monat = rnd.generate() % 11 + 1;
    int jahr = rnd.generate() % 128 + 1890;
    QDate date(jahr, monat, tag);
    int lebensnummer = rnd.generate() % 1000;

    return Person(vornameListe_[indexVorname], zunameListe_[indexZuname], date, lebensnummer);
}

//! Erzeugt eine Liste mit Personen per Zufallsgenerator.
QList<Person> Person::randomPersonList(const unsigned anzahl)
{
    QList<Person> list;
    for (unsigned count=0; count<anzahl; ++count)
    {
        list << randomPerson();
    }

    return list;
}

//! Zufaellige Auftragsnummer.
unsigned Person::randomAuftragNummer()
{
    return QRandomGenerator::global()->generate() % 6000;
}

//! Zufaellige eGK.
QString Person::RandomEgkNummer()
{
    int letter = QRandomGenerator::global()->generate() % 26;
    QString egk('A'+letter);
    for (unsigned count=0; count<9; ++count)
    {
        egk.append(QString::number(QRandomGenerator::global()->generate() % 10));
    }

    return egk;
}

QStringList Person::header()
{
    return m_header;
}

void Person::setHeader(const QStringList &header)
{
    m_header = header;
}
