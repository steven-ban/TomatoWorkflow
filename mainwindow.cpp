#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMessageBox>
#include<QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(updateTimelength(double)));
    //init progressbar
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(this->timelength);
    ui->progressBar->setValue(0);
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startTimer()));

    connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseTimer()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopTimer()));
    connect(&(this->timer), SIGNAL(timeout()), this, SLOT(timeoutAlert()));

    //this->updateProgressBar();

}

void MainWindow::updateTimelength(double time){
    // time set by double spin box, in min
    this->timelength = (int)time * 60; // in s
}

// this function now is wrong
void MainWindow::pauseTimer(){
    this->timelength -= this->stopTime.elapsed();
    this->timer.setInterval(this->timelength);
    this->stopTime = QTime::currentTime();
    this->timer.stop();

    QMessageBox msgBox;
    msgBox.setText(tr("Timer paused. Task time remains (s) : "));
    msgBox.setInformativeText(QString::number(this->timelength / 1000));
    msgBox.exec();
}

void MainWindow::stopTimer(){
    double elapsedTime = this->stopTime.elapsed();
    this->stopTime = QTime::currentTime();
    this->timer.stop();

    QMessageBox msgBox;
    msgBox.setText(tr("Task time elapsed (s) : "));
    msgBox.setInformativeText(QString::number(elapsedTime / 1000));
    msgBox.exec();
}

void MainWindow::startTimer(){
    this->startTime = QTime::currentTime(); // use startTime to record init time, it will not change during timer
    this->stopTime = QTime::currentTime();
    this->stopTime.start(); // use stopTime to record current time
    this->timer.start();
    this->timer.setInterval(1000);  // every 1s, change window components
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::timeoutAlert(){
    this->timer.stop();
    this->stopTime = QTime::currentTime();

    ui->progressBar->setValue(stopTime.elapsed());
    ui->progressBar->update();

    QMessageBox msgBox ;
    msgBox.setText(tr("Time up! Get up and walk for a while!"));
    msgBox.exec();

}
