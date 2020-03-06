#include "model.h"
#include<QString>

model::model()
{
    this->num1=0;
    this->num2=0;
}

void model::setnum1(int num)
{
    this->num1 = num;
}

void model::setnum2(int num)
{
    this->num2 = num;
}

void model::setflag(QString flag)
{
    this->flag = flag;
}

QString model::doExpr()
{
    int res=0;
    if(this->flag=="+"){
        res=this->num1+this->num2;
    }else{if(this->flag=="-"){
            res=this->num1-this->num2;
        }else{if(this->flag=="*"){
                res=this->num1*this->num2;
            }else{if(this->flag=="/"){
                    res=this->num1/this->num2;
                }else{
                    return QString::number(num1);
                }
            }
        }
    }

    return QString::number(res);
}

//QString model::doCircularFun()
//{
//    return
//}
