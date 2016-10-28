#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_task_edit.h"

#include<QMessageBox>
#include<QTime>
#include<QDebug>
#include<QSqlQuery>
#include<QLatin1String>
#include<QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->elapsedTime = 0;

    this->addWidget = new QWidget;
    this->ui_task = new Ui_task_edit;
    this->ui_task->setupUi(this->addWidget);
    connect(ui_task->addButton, SIGNAL(clicked()), this, SLOT(addSQL()));
    connect(ui_task->cancelButton, SIGNAL(clicked()), this->addWidget, SLOT(close()));
    this->addWidget->close();

    // init database
    this->initDb();

    // create SQL connection
    if(this->db.isOpen()){
        this->model = new QSqlTableModel(this, this->db);
        this->model->setTable("task");
        this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        this->model->select();
        this->model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        this->model->setHeaderData(1, Qt::Horizontal, tr("Name"));
        this->model->setHeaderData(2, Qt::Horizontal, tr("Date"));
        this->model->setHeaderData(3, Qt::Horizontal, tr("Start time"));
        this->model->setHeaderData(4, Qt::Horizontal, tr("Stop time"));
        this->model->setHeaderData(5, Qt::Horizontal, tr("Elapsed"));
        this->model->setHeaderData(6, Qt::Horizontal, tr("Description"));

        this->ui->tableView->setModel(this->model);
        this->ui->tableView->hideColumn(0);
        this->ui->tableView->show();
    } else {
        QMessageBox msgBox;
        msgBox.setText(tr("Connecting Database Error!"));
        msgBox.setInformativeText(tr("Fail while Connecting to datase! Plase Check your installation."));
        msgBox.exec();
    }

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseTimer()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopTimer()));


}

QSqlError MainWindow::initDb(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("workflow");
    if(db.open()){
        QSqlQuery q(db);
        q.exec(QLatin1String("create table task("
                             "id integer primary key, "
                             "name varchar, "
                             "thedate date,"
                             "starttime varchar, "
                             "stoptime varchar, "
                             "elapsedtime varchar, "
                             "description varchar)"));
        this->ui->statusBar->showMessage(tr("Initializing database..."));
    } else {
        this->ui->statusBar->showMessage(tr("Opening database error!"));
    }

    return QSqlError();
}

void MainWindow::addSQL(){
    qDebug()<<"addSql slot called.";

    // add to sqlite
    QSqlQuery q(this->db);
    if(this->db.isOpen()){
        q.prepare("INSERT INTO task (name, thedate, starttime, stoptime, elapsedtime, description) "
                  "VALUES (:name, :thedate, :starttime, :stoptime, :elapsedtime, :description)");
        q.bindValue(":name", this->ui_task->lineEdit->text().toLatin1());
        q.bindValue(":thedate", QDate::currentDate().toString().toLatin1());
        q.bindValue(":starttime", this->startTime.toString().toLatin1());
        q.bindValue(":stoptime", this->stopTime.toString().toLatin1());
        q.bindValue(":elapsedtime", QString::number(this->elapsedTime));
        q.bindValue(":description", this->ui_task->textEdit->document()->toPlainText().toLatin1());
        q.exec();
        // q.exec("INSERT INTO task (name, thedate, starttime, stoptime, elapsedtime, description) "
        //          "VALUES ('test', 2016/10/12, '19:30', '19:32', 33, 'test')");
        // qDebug()<<"sql is written.";
    }

    this->addWidget->close();

    this->ui->tableView->update();
}


// this function now is wrong
void MainWindow::pauseTimer(){
    this->stopTime = QTime::currentTime();
    this->elapsedTime += this->stopTime.elapsed() / 1000;
    this->ui->statusBar->showMessage(tr("Timer paused."));

    QMessageBox msgBox;
    msgBox.setText(tr("Timer paused."));
    msgBox.setInformativeText(QString::number(this->elapsedTime));
    msgBox.exec();
}

void MainWindow::stopTimer(){
    // stop by click stop button
    this->elapsedTime += this->stopTime.elapsed() / 1000;
    this->ui_task->startLabel->setText(this->startTime.toString());
    this->ui_task->stopLabel->setText(this->stopTime.toString());
    this->ui_task->elapsedLabel->setText(QString::number(this->elapsedTime));
    this->ui_task->lineEdit->clear();
    this->ui_task->textEdit->clear();
    this->addWidget->update();
    this->addWidget->show();

    this->ui->statusBar->showMessage(tr("Timer stopped."));
}

void MainWindow::startTimer(){
    this->startTime = QTime::currentTime(); // use startTime to record init time, it will not change during timer
    this->stopTime = QTime::currentTime();
    this->stopTime.start();

    this->ui->statusBar->showMessage(tr("Timer started."));
}

MainWindow::~MainWindow()
{
    delete ui;
}
