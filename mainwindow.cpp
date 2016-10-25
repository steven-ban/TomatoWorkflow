#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>
#include<QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->doubleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateTimelength(int)));
    //init progressbar
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(this->timelength);
    ui->progressBar->setValue(0);
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startTimer()));

    connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseTimer()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopTimer()));

    //this->updateProgressBar();

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
    int elapsedTime = this->stopTime.elapsed();
    this->stopTime = QTime::currentTime();

    QMessageBox msgBox;
    msgBox.setText(tr("Task time elapsed (min) : "));
    msgBox.setInformativeText(QString::number(elapsedTime / 60));
    msgBox.exec();
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
