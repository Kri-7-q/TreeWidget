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
    void changeItemSelection() const;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
