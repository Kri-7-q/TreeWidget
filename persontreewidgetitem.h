#ifndef PERSONTREEWIDGETITEM_H
#define PERSONTREEWIDGETITEM_H

#include <QTreeWidgetItem>

class Person;

class PersonTreeWidgetItem : public QTreeWidgetItem
{
public:
    PersonTreeWidgetItem();
    PersonTreeWidgetItem(const Person &p);

    void setSelectionMark(const bool isMarked = true);
    bool isMarked() const       { return m_isSelected; }

    static PersonTreeWidgetItem* headerItem();

private:
    bool m_isSelected = false;
};

#endif // PERSONTREEWIDGETITEM_H
