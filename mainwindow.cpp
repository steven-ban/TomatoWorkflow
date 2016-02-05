#include "mainwindow.h"
#include "initdb.h"

#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Tomato Workflow"));
    setMinimumSize(800, 600);

    // draw the window layouts
    toolBar = new QToolBar(tr("T&Imer"), this);
    startAct = new QAction(tr("&Start"), this);
    pauseAct = new QAction(tr("&Pause"), this);
    stopAct = new QAction(tr("S&Top"), this);
    toolBar->addAction(startAct);
    toolBar->addAction(pauseAct);
    toolBar->addAction(stopAct);
    addToolBar(toolBar);

    // test database fetchable
    if(!QSqlDatabase::drivers().contains("QSQLITE"))
        QMessageBox::critical(this, tr("Load database error!"), tr("This application needs SQLITE driver!"));

    //initialize the database
    QSqlError err = initDb();
    if(err.type() != QSqlError::NoError){
        showError(err);
        return;
    }

    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("tomato_record");
    taskNameIdx = model->fieldIndex("task_name");
    startDateIdx = model->fieldIndex("start_date");
    startTimeIdx = model->fieldIndex("start_time");
    stopTimeIdx = model->fieldIndex("stop_time");
    model->setHeaderData(taskNameIdx, Qt::Horizontal, tr("Task Name"));
    model->setHeaderData(startDateIdx, Qt::Horizontal, tr("Task Date"));
    model->setHeaderData(startTimeIdx, Qt::Horizontal, tr("Start Time"));
    model->setHeaderData(stopTimeIdx, Qt::Horizontal, tr("Stop Time"));

    // populate the model
    if(!model->select()){
        showError(model->lastError());
        return;
    }


    catogeryView = new QListView(this);
    workflowView = new QTableView(this);
    workflowView->setModel(model);
    workflowView->hideColumn(0);
    centerLayout = new QHBoxLayout();
    centerWidget = new QWidget(this);
    centerLayout->addWidget(catogeryView);
    centerLayout->addWidget(workflowView);
    centerWidget->setLayout(centerLayout);
    setCentralWidget(centerWidget);




}

void MainWindow::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}

MainWindow::~MainWindow()
{

}
