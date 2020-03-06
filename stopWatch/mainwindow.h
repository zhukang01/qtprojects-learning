#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>

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
    void updateTimeandDisplay();


    void on_btn_start_clicked();

    void on_btn_stop_clicked();

    void on_btn_pause_clicked();

    void on_btn_log_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* ptimer;
    QTime basetime;
    QString showStr;
};

#endif // MAINWINDOW_H
