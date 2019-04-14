#include "persontreewidgetitem.h"
#include "personobj.h"

PersonTreeWidgetItem::PersonTreeWidgetItem(const PersonObj &p)
    : QTreeWidgetItem()
{
    for (const QString &text : Person::header())
    {
        setData(0, Qt::DisplayRole, p.property(text.toLower().toLatin1().data()));
    }
}

PersonTreeWidgetItem* PersonTreeWidgetItem::headerItem()
{
    PersonTreeWidgetItem *item = new PersonTreeWidgetItem;
    int index = 0;
    for (QString text : Person::header())
    {
        item->setText(index, text);
    }

    return item;
}
