#include "task_edit.h"
#include "ui_task_edit.h"

task_edit::task_edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task_edit)
{
    ui->setupUi(this);
}

task_edit::~task_edit()
{
    delete ui;
}
