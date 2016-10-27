#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QTime>
#include<QtSql>

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
    QTime startTime;
    QTime stopTime;
    int timelength;    // time length set for a period, in minute

private slots:
    void timeoutAlert();    // when a timer period is up, change window components
    void startTimer();
    void stopTimer();
    void pauseTimer();
};

#endif // MAINWINDOW_H
