#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_task_edit.h"

#include<QMessageBox>
#include<QTime>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->doubleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateTimelength(int)));

    this->addWidget = new QWidget;
    this->ui_task = new Ui_task_edit;
    this->ui_task->setupUi(this->addWidget);
    connect(ui_task->addButton, SIGNAL(clicked()), this, SLOT(addSQL()));
    connect(ui_task->cancelButton, SIGNAL(clicked()), this->addWidget, SLOT(close()));
    this->addWidget->close();


    // create SQL connection
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    if(this->db.open()){
        this->model = new QSqlTableModel(this, this->db);
        this->model->setTable("Task");
        this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        this->model->select();
        this->model->setHeaderData(0, Qt::Horizontal, tr("Name"));
        this->model->setHeaderData(1, Qt::Horizontal, tr("Date"));
        this->model->setHeaderData(2, Qt::Horizontal, tr("Start time"));
        this->model->setHeaderData(3, Qt::Horizontal, tr("Stop time"));
        this->model->setHeaderData(4, Qt::Horizontal, tr("Elapsed"));
        this->model->setHeaderData(5, Qt::Horizontal, tr("Description"));

        this->ui->tableView->setModel(this->model);
        this->ui->tableView->show();
    } else {
        QMessageBox msgBox;
        msgBox.setText(tr("Connecting Database Error!"));
        msgBox.setInformativeText(tr("Fail while Connecting to datase! Plase Check your installation."));
        msgBox.exec();
    }

    //init progressbar
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(this->timelength);
    ui->progressBar->setValue(0);
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startTimer()));

    connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseTimer()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopTimer()));

    //this->updateProgressBar();


}

void MainWindow::addSQL(){
    qDebug()<<"addSql slot called.";
    this->addWidget->close();
}


// this function now is wrong
void MainWindow::pauseTimer(){
    this->timelength -= this->stopTime.elapsed();
    this->stopTime = QTime::currentTime();

    QMessageBox msgBox;
    msgBox.setText(tr("Timer paused. Task time remains (s) : "));
    msgBox.setInformativeText(QString::number(this->timelength / 1000));
    msgBox.exec();
}

void MainWindow::stopTimer(){
    // stop by click stop button
    // int elapsedTime = this->stopTime.elapsed();
    this->ui_task->startLabel->setText(this->startTime.toString());
    this->ui_task->stopLabel->setText(this->stopTime.toString());
    this->ui_task->elapsedLabel->setText(QString::number(this->stopTime.elapsed()));
    this->addWidget->update();
    this->addWidget->show();



}

void MainWindow::startTimer(){
    this->startTime = QTime::currentTime(); // use startTime to record init time, it will not change during timer
    this->stopTime = QTime::currentTime();
    this->stopTime.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::timeoutAlert(){
    this->stopTime = QTime::currentTime();

    ui->progressBar->setValue(stopTime.elapsed());
    ui->progressBar->update();

    QMessageBox msgBox ;
    msgBox.setText(tr("Time up! Get up and walk for a while!"));
    msgBox.exec();

}
