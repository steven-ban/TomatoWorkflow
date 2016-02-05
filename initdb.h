#ifndef INITDB_H
#define INITDB_H

#include<QtSql>

QVariant addTask(QSqlQuery& q, const QString& name, const QDate& date, const QTime& startTime, const QTime& stopTime)
{
    q.addBindValue(name);
    q.addBindValue(date);
    q.addBindValue(startTime);
    q.addBindValue(stopTime);
    q.exec();
    return q.lastInsertId();
}

QSqlError initDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("workflow");

    if(!db.open())
        return db.lastError();

    QStringList tables = db.tables();
    if(tables.contains("tomato_record", Qt::CaseInsensitive))
        return QSqlError();

    QSqlQuery q;
    if(!q.exec(QLatin1String("create table tomato_record(id integer primary key, task_name varchar, start_date date, start_time time, stop_time time)")))
        return q.lastError();

    if(!q.prepare(QLatin1String("insert into tomato_record(task_name, start_date, start_time, stop_time) values(?, ?, ?, ?)")))
        return q.lastError();
    QVariant test1ID = addTask(q, QLatin1String("test 1"), QDate(1999, 9, 1), QTime(13, 2, 2), QTime(13, 27, 15));
    QVariant test2ID = addTask(q, QLatin1String("test 2"), QDate(1999, 9, 1), QTime(15, 2, 2), QTime(15, 27, 15));
    QVariant test3ID = addTask(q, QLatin1String("test 3"), QDate(1999, 9, 1), QTime(16, 2, 2), QTime(16, 27, 15));
    QVariant test4ID = addTask(q, QLatin1String("test 4"), QDate(1999, 9, 1), QTime(17, 2, 2), QTime(17, 27, 15));

    return QSqlError();
}

#endif // INITDB_H

