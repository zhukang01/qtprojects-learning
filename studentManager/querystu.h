#ifndef QUERYSTU_H
#define QUERYSTU_H

#include <QDialog>
#include <QFile>
#include <QList>
#include <QString>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class queryStu;
}

class queryStu : public QDialog
{
    Q_OBJECT

public:
    explicit queryStu(QWidget *parent = 0);
    ~queryStu();
    int readFromFile();
    void doQuery(int index,QString cnt);
    void dispay(int row,QStringList subs);
    void setTableHead();

private slots:
    void on_btn_search_clicked();

private:
    Ui::queryStu *ui;
    QList<QString> stu_lines;
    QStandardItemModel* model;
};

#endif // QUERYSTU_H
