#ifndef TASK_EDIT_H
#define TASK_EDIT_H

#include <QWidget>

namespace Ui {
class task_edit;
}

class task_edit : public QWidget
{
    Q_OBJECT

public:
    explicit task_edit(QWidget *parent = 0);
    ~task_edit();

private:
    Ui::task_edit *ui;
};

#endif // TASK_EDIT_H
