#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "persontreewidgetitem.h"
#include "treewidgetitemfactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setStyleSheet("QTreeWidget{  selection-background-color: #409090ff }");
    ui->setupUi(this);
    fillLeftList();
    ui->twLinks->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//! Override:   Fange Pfeiltaste -> rechts.
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    QTreeWidget *treeWidget = dynamic_cast<QTreeWidget*>(watched);
    if (treeWidget && treeWidget->objectName() == ui->twLinks->objectName())
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(event);
            if (keyEvent && keyEvent->key() == Qt::Key_Right)
            {
                eintragInRechteListe();
                return true;
            }
        }
    }

    return false;
}

//! Fuegt der linken Liste einen Inhalt ein.
void MainWindow::fillLeftList()
{
    // Header rechts
    QStringList list2 = { "Index", "Auftragsnummer", "eGK" };
    PersonTreeWidgetItem *header = PersonTreeWidgetItem::headerItem(list2);
    ui->twRechts->setHeaderItem(header);
    // Header links
    QStringList list = { "Lebensnummer", "Zuname", "Vorname", "Geburtsdatum" };
    header = PersonTreeWidgetItem::headerItem(list);
    ui->twLinks->setHeaderItem(header);

    TreeWidgetItemFactory::init();
    PersonTreeWidgetItem::setModel(Person::randomPersonList(20));
    for(Person &p : PersonTreeWidgetItem::model())
    {
        PersonTreeWidgetItem *item = TreeWidgetItemFactory::personItem(header, &p);
        ui->twLinks->addTopLevelItem(item);
    }
}

void MainWindow::changeItemSelection() const
{
    for (int index=0; index<ui->twLinks->topLevelItemCount(); ++index)
    {
        PersonTreeWidgetItem *item = dynamic_cast<PersonTreeWidgetItem*>( ui->twLinks->topLevelItem(index) );
        if (item->isMarked())
            item->setSelectionMark(false);
    }
    PersonTreeWidgetItem *item = dynamic_cast<PersonTreeWidgetItem*>( ui->twLinks->currentItem() );
    item->setSelectionMark(true);
}

//! Eintrag in rechter Liste machen.
void MainWindow::eintragInRechteListe()
{
    changeItemSelection();
    int current = ui->twLinks->selectionModel()->currentIndex().row();
    Person &p = PersonTreeWidgetItem::model()[current];
    QTreeWidgetItem *header = ui->twRechts->headerItem();
    PersonTreeWidgetItem *item = TreeWidgetItemFactory::personItem(header, &p);
    ui->twRechts->addTopLevelItem(item);
}
