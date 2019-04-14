#ifndef PERSONTREEWIDGETITEM_H
#define PERSONTREEWIDGETITEM_H

#include <QTreeWidgetItem>

class PersonObj;

class PersonTreeWidgetItem : public QTreeWidgetItem
{
public:
    PersonTreeWidgetItem(const PersonObj &p);

    static PersonTreeWidgetItem* headerItem();

private:
    PersonTreeWidgetItem() {}
};

#endif // PERSONTREEWIDGETITEM_H
