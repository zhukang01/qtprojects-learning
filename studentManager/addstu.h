#ifndef ADDSTU_H
#define ADDSTU_H

#include <QDialog>

namespace Ui {
class addStu;
}

class addStu : public QDialog
{
    Q_OBJECT

public:
    explicit addStu(QWidget *parent = 0);
    ~addStu();
    void clearUserInterface();
    void writetofile(QString cnt);

private slots:
    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::addStu *ui;
};

#endif // ADDSTU_H
