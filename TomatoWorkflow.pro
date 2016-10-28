#-------------------------------------------------
#
# Project created by QtCreator 2016-03-05T18:34:28
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TomatoWorkflow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    task_edit.cpp

HEADERS  += mainwindow.h \
    task_edit.h \
    ui_task_edit.h

FORMS    += mainwindow.ui \
    task_edit.ui
