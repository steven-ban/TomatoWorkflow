#include "tasktimer.h"

void TaskTimer::TaskTimer(){
    this->startTime(QTime::currentTime());
    this->startTime(startTime);

}

void TaskTimer::start(){


    this->startTime = QTime::currentTime();

}

void TaskTime::stop(){

}

void TaskTime::pause(){

}
