#include "persontreewidgetitem.h"
#include "person.h"
#include <utility>

QList<Person> PersonTreeWidgetItem::model_;

PersonTreeWidgetItem::PersonTreeWidgetItem()
    : QTreeWidgetItem()
{

}

PersonTreeWidgetItem::PersonTreeWidgetItem(const int index)
    : QTreeWidgetItem()
    , modelindex_(index)
{
    setData(0, Qt::DisplayRole, model_[index].lebensnummer());
    setData(1, Qt::DisplayRole, model_[index].zuname());
    setData(2, Qt::DisplayRole, model_[index].vorname());
    setData(3, Qt::DisplayRole, model_[index].geburtsdatum());
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

PersonTreeWidgetItem* PersonTreeWidgetItem::headerItem(const QStringList &nameList)
{
    PersonTreeWidgetItem *item = new PersonTreeWidgetItem;
    int index = 0;
    for (QString text : nameList)
    {
        item->setText(index, text);
        ++index;
    }

    return item;
}

QList<Person> PersonTreeWidgetItem::model()
{
    return model_;
}

void PersonTreeWidgetItem::setModel(const QList<Person> &model)
{
    model_ = model;
}

int PersonTreeWidgetItem::modelindex() const
{
    return modelindex_;
}

void PersonTreeWidgetItem::setModelindex(const int modelindex)
{
    modelindex_ = modelindex;
}
