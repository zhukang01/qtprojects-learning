#include "addstu.h"
#include "ui_addstu.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QList>
#include <QAbstractButton>
#include <QCheckBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

addStu::addStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStu)
{
    ui->setupUi(this);
}

addStu::~addStu()
{
    delete ui;
}

void addStu::on_btn_ok_clicked()
{
    QString name = this->ui->le_name->text();
    QString id = this->ui->le_id->text();
    QString sex = this->ui->sexGroup->checkedButton()->text();

    QList<QAbstractButton *> ins_list = this->ui->insGroup->buttons();
    QString ins;
    for(int i=0;i<ins_list.length();i++){
        QAbstractButton * che = ins_list.at(i);
        if(che->isChecked()){
            ins += che->text() + " ";
        }
    }
    ins.chop(1);

    QString age = this->ui->cbb_age->currentText();
    QString institute = this->ui->cbb_y->currentText();


    QString content = name + '\n' + id + '\n' + sex + '\n' + age + '\n' + institute + '\n' + ins ;
    QString cnt = name + ' ' + id + ' ' + sex + ' ' + age + ' ' + institute + ' ' + ins + '\n' ;

//    QMessageBox msgBox;

//    msgBox.setText("请确认信息");
//    msgBox.setInformativeText(name + '\n' + id);
//    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
//    msgBox.setDefaultButton(QMessageBox::Save);

//    msgBox.addButton("确认",QMessageBox::AcceptRole);
//    msgBox.addButton("取消",QMessageBox::RejectRole);
//    msgBox.setDefaultButton();
//    int ret = msgBox.exec();

//    QMessageBox::aboutQt(this,"xie");

    if(name.length()<1 || id.length()<10 || ins.length()<1){
        QMessageBox::critical(this,"错误","填写不完整","确定");
    }else{
        int ret = QMessageBox::information(this,"确认信息",content,"确认","取消");
        if(ret == 0)
        {
            writetofile(cnt);
            clearUserInterface();
        }
    }


}


void addStu::clearUserInterface()
{
    this->ui->le_name->clear();
    this->ui->le_id->clear();
    this->ui->rdtn_male->setChecked(true);
    this->ui->cbb_age->setCurrentIndex(0);
    this->ui->cbb_y->setCurrentIndex(0);
    QList<QAbstractButton*> ins_list = this->ui->insGroup->buttons();
    for(int i=0;i<ins_list.length();i++){
        QAbstractButton* che = ins_list.at(i);
        che->setChecked(false);
    }
    this->ui->le_name->setFocus();

}

void addStu::writetofile(QString cnt)
{
    QFile file("data.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::critical(this,"警告","文件打开错误","确认");
        return;
    }

    QTextStream out(&file);
    out << cnt;
    file.close();

}


void addStu::on_btn_cancel_clicked()
{
    this->close();
}
