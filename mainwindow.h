#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_task_edit.h"

#include <QMainWindow>
#include<QTimer>
#include<QTime>
#include<QSqlDatabase>
#include<QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Ui_task_edit *ui_task;
    QWidget *addWidget; // to show add action after stop.

    QTime startTime;
    QTime stopTime;
    int timelength;    // time length set for a period, in minute
    // database related members
    QSqlDatabase db;
    QSqlTableModel *model;

private slots:
    void timeoutAlert();    // when a timer period is up, change window components
    void startTimer();
    void stopTimer();
    void pauseTimer();
    void addSQL();
};

#endif // MAINWINDOW_H
