#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QToolBar>
#include<QListView>
#include<QHBoxLayout>
#include<QAction>
#include<QtSql>
#include<QTableView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QAction* startAct;
    QAction* pauseAct;
    QAction* stopAct;
    QToolBar* toolBar;
    QListView* catogeryView;
    QTableView* workflowView;
    QHBoxLayout* centerLayout;
    QWidget* centerWidget;
    int taskNameIdx, startDateIdx, startTimeIdx, stopTimeIdx;

    void showError(const QSqlError &err);
};

#endif // MAINWINDOW_H
