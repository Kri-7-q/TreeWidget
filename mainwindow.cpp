#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "persontreewidgetitem.h"
#include "personobj.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    personenListe_(Person::randomPersonList(15))
{
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
    QTreeWidgetItem *header = new QTreeWidgetItem;
    header->setText(0, "Lebensnummer");
    header->setText(1, "Zuname");
    header->setText(2, "Vorname");
    header->setText(3, "Geburtsdatum");
    ui->twLinks->setHeaderItem(header);
    // Header rechts
    header = new QTreeWidgetItem;
    header->setText(0, QString("Lebensnummer"));
    header->setText(1, QString("Auftragsnummer"));
    header->setText(2, QString("eGK Nummer"));
    ui->twRechts->setHeaderItem(header);

    QString format("dd.MM.yyyy");
    for(const Person &person : personenListe_)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem;
        item->setData(0, Qt::DisplayRole, person.lebensnummer());
        item->setData(1, Qt::DisplayRole, person.zuname());
        item->setData(2, Qt::DisplayRole, person.vorname());
        item->setData(3, Qt::DisplayRole, person.geburtsdatum());
        ui->twLinks->addTopLevelItem(item);
    }
}

//! Eintrag in rechter Liste machen.
void MainWindow::eintragInRechteListe()
{
    int current = ui->twLinks->selectionModel()->currentIndex().row();
    const Person &p = personenListe_[current];
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setData(0, Qt::DisplayRole, p.lebensnummer());
    item->setData(1, Qt::DisplayRole, Person::randomAuftragNummer());
    item->setData(2, Qt::DisplayRole, Person::RandomEgkNummer());
    ui->twRechts->addTopLevelItem(item);
}
