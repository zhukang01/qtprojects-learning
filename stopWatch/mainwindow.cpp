#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptimer = new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(updateTimeandDisplay()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateTimeandDisplay()
{
    QTime current = QTime::currentTime();
    int t = this->basetime.msecsTo(current);
    QTime showtime(0,0,0,0);
    showtime = showtime.addMSecs(t);
    showStr = showtime.toString("hh:mm:ss:zzz");
    this->ui->lcdNumber->display(showStr);

//    this->basetime = this->basetime.addMSecs(1);
//    QString showStr = basetime.toString("hh:mm:ss:zzz");
//    this->ui->lcdNumber->display(showStr);
}

void MainWindow::on_btn_start_clicked()
{
//    this->basetime.setHMS(0,0,0,0);
    this->basetime=QTime::currentTime();
    this->ptimer->start(1);
    this->ui->btn_start->setEnabled(false);
}

void MainWindow::on_btn_stop_clicked()
{
//    方法一：停止定时器
    if(this->ui->btn_stop->text()=="停止"){
        this->ui->btn_stop->setText("清零");
        this->ptimer->stop();
        this->ui->btn_pause->setEnabled(false);
    }else{
        this->ui->lcdNumber->display("00:00:00:000");
        this->ui->textBrowser->clear();
        this->ui->btn_stop->setText("停止");
        this->ui->btn_start->setEnabled(true);
        this->ui->btn_pause->setEnabled(true);
    }

//    方法二：断开timeout信号和函数的绑定
}

void MainWindow::on_btn_pause_clicked()
{
    static QTime pausetime;

    if(this->ui->btn_pause->text()=="暂停"){
        pausetime = QTime::currentTime();

        this->ptimer->stop();
        this->ui->btn_pause->setText("继续");
        this->ui->btn_stop->setEnabled(false);
    }else{
        QTime cuttime = QTime::currentTime();
        int t = pausetime.msecsTo(cuttime);
        this->basetime = this->basetime.addMSecs(t);

        this->ptimer->start(1);
        this->ui->btn_pause->setText("暂停");
        this->ui->btn_stop->setEnabled(true);
    }

}

void MainWindow::on_btn_log_clicked()
{
    this->ui->textBrowser->append(this->showStr);
}


