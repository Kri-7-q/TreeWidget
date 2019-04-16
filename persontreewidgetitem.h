#ifndef PERSONTREEWIDGETITEM_H
#define PERSONTREEWIDGETITEM_H

#include <QTreeWidgetItem>

class Person;

class PersonTreeWidgetItem : public QTreeWidgetItem
{
public:
    PersonTreeWidgetItem();
    PersonTreeWidgetItem(const int index);

    void setSelectionMark(const bool isMarked = true);
    bool isMarked() const       { return m_isSelected; }

    static PersonTreeWidgetItem* headerItem(const QStringList &nameList);
    static QList<Person> model();
    static void setModel(const QList<Person> &model);
    int modelindex() const;
    void setModelindex(const int modelindex);

private:
    bool m_isSelected = false;
    int modelindex_ = 0;
    static QList<Person> model_;
};

#endif // PERSONTREEWIDGETITEM_H
