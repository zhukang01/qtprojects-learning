#include "querystu.h"
#include "ui_querystu.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QStringList>


queryStu::queryStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::queryStu)
{
    ui->setupUi(this);
    if(readFromFile()==-1){
        QMessageBox::critical(this,"error","文件打开失败请重试");
        this->close();
    }
    setTableHead();

}

queryStu::~queryStu()
{
    delete ui;
}


int queryStu::readFromFile()
{
    QFile file("data.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1;
    }

    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        stu_lines.append(line);
    }
    file.close();
    /*for(auto &i : stu_lines){
        qDebug()<<i;
    }*/
    return 0;
}

void queryStu::on_btn_search_clicked()
{
    this->model->clear();
    setTableHead();
    int index = this->ui->cbb_method->currentIndex();
    QString cnt = this->ui->le_cnt->text();
    doQuery(index,cnt);
}

void queryStu::doQuery(int index, QString cnt)
{
    int row = 0;
    for(int i=0;i<stu_lines.length();i++){
        QString lines = stu_lines.at(i);
        lines = lines.trimmed();
        QStringList subs = lines.split(" ");

        switch (index) {
        case 1:
            if(cnt==subs.at(0)){
                dispay(row++,subs);
            }
            break;
        case 2:
            if(cnt==subs.at(1)){
                dispay(row++,subs);
            }
            break;
        case 3:
            if(cnt==subs.at(4)){
                dispay(row++,subs);
            }
            break;
        default:
            break;
        }
    }
}

void queryStu::dispay(int row,QStringList subs)
{
    for(int i =0;i<5;i++){
        this->model->setItem(row,i,new QStandardItem(subs.at(i)));
    }
    QString ins;
    for(int i=5;i<subs.length();i++){
        ins+=subs.at(i)+",";
    }
    ins.chop(1);
    this->model->setItem(row,5,new QStandardItem(ins));
}

void queryStu::setTableHead()
{
    this->model = new QStandardItemModel;
    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("院系"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("兴趣"));

    this->ui->tableView->setModel(model);

    this->ui->tableView->setColumnWidth(0,100);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,50);
    this->ui->tableView->setColumnWidth(3,50);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,150);
}


