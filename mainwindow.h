#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_task_edit.h"

#include<QMainWindow>
#include<QTimer>
#include<QTime>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlError>

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
    int elapsedTime;    // time length set for a period, in seconds
    // database related members
    QSqlDatabase db;
    QSqlTableModel *model;

    QSqlError initDb();

private slots:
    void startTimer();
    void stopTimer();
    void pauseTimer();
    void addSQL();
};

#endif // MAINWINDOW_H
