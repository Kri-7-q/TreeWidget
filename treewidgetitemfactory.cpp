#include "treewidgetitemfactory.h"
#include "person.h"

QHash<QString, TreeWidgetItemFactory::Property> TreeWidgetItemFactory::attributeTable_;

void TreeWidgetItemFactory::init()
{
    attributeTable_.insert("Lebensnummer", Lebensnummer);
    attributeTable_.insert("Vorname", Vorname);
    attributeTable_.insert("Zuname", Zuname);
    attributeTable_.insert("Geburtsdatum", Geburtsdatum);
    attributeTable_.insert("eGK", eGK);
    attributeTable_.insert("Auftragsnummer", AuftragsNr);
    attributeTable_.insert("Index", Index);
}

PersonTreeWidgetItem *TreeWidgetItemFactory::personItem(QTreeWidgetItem *header, Person *person)
{
    PersonTreeWidgetItem *item = new PersonTreeWidgetItem;
    for (int column=0; column<header->columnCount(); ++column)
    {
        QString title = header->text(column);
        Property prop = attributeTable_.value(title);
        QVariant value = valueOf(person, prop);
        item->setData(column, Qt::DisplayRole, value);
    }

    return item;
}

QVariant TreeWidgetItemFactory::valueOf(Person *person, TreeWidgetItemFactory::Property property)
{
    QVariant value;
    switch (property) {
    case Lebensnummer:
        value.setValue(person->lebensnummer());
        break;
    case Vorname:
        value.setValue(person->vorname());
        break;
    case Zuname:
        value.setValue(person->zuname());
        break;
    case Geburtsdatum:
        value.setValue(person->geburtsdatum());
        break;
    case eGK:
        value.setValue(person->egk());
        break;
    case AuftragsNr:
        value.setValue(person->auftragsNr());
        break;
    case Index:
        value.setValue(person->index());
        break;
    }

    return value;
}
