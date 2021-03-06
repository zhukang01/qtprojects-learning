#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <addstu.h>
//#include <querystu.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionaddStu_triggered();

    void on_actionqueryStu_triggered();

private:
    Ui::MainWindow *ui;
    addStu a;
//    queryStu q;
};

#endif // MAINWINDOW_H
