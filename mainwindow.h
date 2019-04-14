#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "person.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool eventFilter(QObject *watched, QEvent *event) override;

public slots:
    void eintragInRechteListe();

protected:
    void fillLeftList();

private:
    Ui::MainWindow *ui;
    QList<Person> personenListe_;
};

#endif // MAINWINDOW_H