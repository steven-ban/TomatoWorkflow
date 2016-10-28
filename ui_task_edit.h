/********************************************************************************
** Form generated from reading UI file 'task_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_EDIT_H
#define UI_TASK_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_task_edit
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *startLabel;
    QLabel *stopLabel;
    QLabel *elapsedLabel;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *addButton;

    void setupUi(QWidget *task_edit)
    {
        if (task_edit->objectName().isEmpty())
            task_edit->setObjectName(QStringLiteral("task_edit"));
        task_edit->resize(457, 512);
        verticalLayout_2 = new QVBoxLayout(task_edit);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(task_edit);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        groupBox = new QGroupBox(task_edit);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startLabel = new QLabel(groupBox);
        startLabel->setObjectName(QStringLiteral("startLabel"));

        horizontalLayout->addWidget(startLabel);

        stopLabel = new QLabel(groupBox);
        stopLabel->setObjectName(QStringLiteral("stopLabel"));

        horizontalLayout->addWidget(stopLabel);

        elapsedLabel = new QLabel(groupBox);
        elapsedLabel->setObjectName(QStringLiteral("elapsedLabel"));

        horizontalLayout->addWidget(elapsedLabel);


        verticalLayout->addLayout(horizontalLayout);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancelButton = new QPushButton(task_edit);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        addButton = new QPushButton(task_edit);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_2->addWidget(addButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(task_edit);

        QMetaObject::connectSlotsByName(task_edit);
    } // setupUi

    void retranslateUi(QWidget *task_edit)
    {
        task_edit->setWindowTitle(QApplication::translate("task_edit", "Form", 0));
        label->setText(QApplication::translate("task_edit", "Task complete. Please edit the profile:", 0));
        groupBox->setTitle(QApplication::translate("task_edit", "Task profile", 0));
        startLabel->setText(QApplication::translate("task_edit", "start", 0));
        stopLabel->setText(QApplication::translate("task_edit", "stop", 0));
        elapsedLabel->setText(QApplication::translate("task_edit", "eplased", 0));
        lineEdit->setInputMask(QString());
        lineEdit->setPlaceholderText(QApplication::translate("task_edit", "Please input the task's name...", 0));
        textEdit->setPlaceholderText(QApplication::translate("task_edit", "Please input the task's description...", 0));
        cancelButton->setText(QApplication::translate("task_edit", "Cancel", 0));
        addButton->setText(QApplication::translate("task_edit", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class task_edit: public Ui_task_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_EDIT_H
