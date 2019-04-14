#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "persontreewidgetitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    personenListe_(Person::randomPersonList(15))
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
    // Header links
    PersonTreeWidgetItem *header = PersonTreeWidgetItem::headerItem();
    ui->twLinks->setHeaderItem(header);
    // Header rechts
    header = new PersonTreeWidgetItem;
    header->setText(0, QString("Id"));
    header->setText(1, QString("Auftragsnummer"));
    header->setText(2, QString("V Nummer"));
    ui->twRechts->setHeaderItem(header);

    for(const Person &person : personenListe_)
    {
        PersonTreeWidgetItem *item = new PersonTreeWidgetItem(person);
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
    const Person &p = personenListe_[current];
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setData(0, Qt::DisplayRole, p.lebensnummer());
    item->setData(1, Qt::DisplayRole, Person::randomAuftragNummer());
    item->setData(2, Qt::DisplayRole, Person::RandomEgkNummer());
    ui->twRechts->addTopLevelItem(item);
}
