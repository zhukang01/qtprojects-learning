#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <addstu.h>
#include <querystu.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionaddStu_triggered()
{
//    addStu w;
//    w.show();
//    w.exec();  //模态视图
    this->a.show();
}

void MainWindow::on_actionqueryStu_triggered()
{
//    this->q.show();
    queryStu q;
    q.exec();
}
