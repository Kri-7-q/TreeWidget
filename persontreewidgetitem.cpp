#include "persontreewidgetitem.h"
#include "person.h"

PersonTreeWidgetItem::PersonTreeWidgetItem()
    : QTreeWidgetItem()
{

}

PersonTreeWidgetItem::PersonTreeWidgetItem(const Person &p)
    : QTreeWidgetItem()
{
    setData(0, Qt::DisplayRole, p.lebensnummer());
    setData(1, Qt::DisplayRole, p.zuname());
    setData(2, Qt::DisplayRole, p.vorname());
    setData(3, Qt::DisplayRole, p.geburtsdatum());
}

void PersonTreeWidgetItem::setSelectionMark(const bool isSelected)
{
    QColor color(255, 255, 255);
    if (isSelected)
        color = QColor(220, 220, 140);
    QBrush brush(color);
    for (int index=0; index<4; ++index)
    {
        setBackground(index, brush);
    }
    m_isSelected = isSelected;
}

PersonTreeWidgetItem* PersonTreeWidgetItem::headerItem()
{
    PersonTreeWidgetItem *item = new PersonTreeWidgetItem;
    int index = 0;
    for (QString text : { "Id", "Zuname", "Vorname", "Geburtsdatum" })
    {
        item->setText(index, text);
        ++index;
    }

    return item;
}
