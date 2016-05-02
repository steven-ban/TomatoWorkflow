#ifndef TASKTIMER
#define TASKTIMER

#include<QTime>

class TaskTimer : public QObject{
    Q_OBJECT

public:
    TaskTimer();
    void start();
    void stop();
    void pause();

private:
    QTime startTime;
    QTime stopTime;
};

#endif // TASKTIMER

