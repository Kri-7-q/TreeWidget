#ifndef TREEWIDGETITEMFACTORY_H
#define TREEWIDGETITEMFACTORY_H

#include "persontreewidgetitem.h"
#include <QHash>

class TreeWidgetItemFactory
{
public:
    static void init();
    static PersonTreeWidgetItem* personItem(QTreeWidgetItem *header, Person *person);

private:
    TreeWidgetItemFactory() {}
    enum Property { Zuname, Vorname, Lebensnummer, eGK, AuftragsNr, Index, Geburtsdatum };
    static QHash<QString, Property> attributeTable_;

private:
    static QVariant valueOf(Person *person, Property property);
};

#endif // TREEWIDGETITEMFACTORY_H
