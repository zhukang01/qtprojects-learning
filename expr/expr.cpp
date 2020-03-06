#include "expr.h"
#include "ui_expr.h"
#include  <QString>

expr::expr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::expr)
{
    ui->setupUi(this);
    connect(this->ui->btn_0,SIGNAL(clicked(bool)),this,SLOT(getBtn0()));
    connect(this->ui->btn_1,SIGNAL(clicked(bool)),this,SLOT(getBtn1()));
    connect(this->ui->btn_2,SIGNAL(clicked(bool)),this,SLOT(getBtn2()));

    this->tmp="";
    this->mode = new model;
}

expr::~expr()
{
    delete ui;
}

// 获取按键值
void expr::getBtn0()
{
    if(this->tmp!=""){
        this->tmp+=this->ui->btn_0->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}

void expr::getBtn1()
{
    this->tmp+=this->ui->btn_1->text();
    this->ui->lbl_display->setText(this->tmp);
}

void expr::getBtn2()
{
    this->tmp+=this->ui->btn_2->text();
    this->ui->lbl_display->setText(this->tmp);
}

void expr::on_btn_3_clicked()
{
    this->tmp+=this->ui->btn_3->text();
    this->ui->lbl_display->setText(this->tmp);
}

void expr::on_btn_4_clicked()
{
    this->tmp+=this->ui->btn_4->text();
    this->ui->lbl_display->setText(this->tmp);
}

void expr::on_btn_5_clicked()
{
    this->tmp+=this->ui->btn_5->text();
    this->ui->lbl_display->setText(this->tmp);
}

void expr::on_btn_6_clicked()
{
    this->tmp+=this->ui->btn_6->text();
    this->ui->lbl_display->setText(this->tmp);
}

void expr::on_btn_7_clicked()
{
    this->tmp+=this->ui->btn_7->text();
    this->ui->lbl_display->setText(this->tmp);
}

void expr::on_btn_8_clicked()
{
    this->tmp+=this->ui->btn_8->text();
    this->ui->lbl_display->setText(this->tmp);
}

void expr::on_btn_9_clicked()
{
    this->tmp+=this->ui->btn_9->text();
    this->ui->lbl_display->setText(this->tmp);
}


// +-*/操作

void expr::on_btn_plus_clicked()
{
    int num = this->tmp.toInt();
    this->mode->setnum1(num);
    this->tmp="";
    QString f = this->ui->btn_plus->text();//获取操作符
    this->mode->setflag(f);
}

void expr::on_btn_sub_clicked()
{
    int num = this->tmp.toInt();
    this->mode->setnum1(num);
    this->tmp="";
    QString f = this->ui->btn_sub->text();
    this->mode->setflag(f);
}

void expr::on_btn_mul_clicked()
{
    int num = this->tmp.toInt();
    this->mode->setnum1(num);
    this->tmp="";
    QString f = this->ui->btn_mul->text();
    this->mode->setflag(f);
}

void expr::on_btn_div_clicked()
{
    int num = this->tmp.toInt();
    this->mode->setnum1(num);
    this->tmp="";
    QString f = this->ui->btn_div->text();
    this->mode->setflag(f);
}

void expr::on_btn_equal_clicked()
{
    this->mode->setnum2(this->tmp.toInt());
    QString result = this->mode->doExpr();
    this->ui->lbl_display->setText(result);
    this->tmp = "";
}

void expr::on_btn_clear_clicked()
{
    this->tmp="";
    this->ui->lbl_display->setText("0");
}

void expr::on_btn_cos_clicked()
{

}

void expr::on_btn_sin_clicked()
{

}
