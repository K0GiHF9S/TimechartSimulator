#include <QThread>
#include <QDebug>
#include "task.h"

Task::Task(quint8 priority, bool ever, QObject *parent) : QObject(parent)
{
    this->priority = priority;
    this->ever = ever;
}

void Task::loop()
{
    do{
        work();
    }while(ever);
}

void Task::work()
{
    static int i = 0;
    qDebug() << "working" << i++;
    QThread::sleep(1);
}

void Task::stop()
{
    qDebug() << "stop";
    ever = false;
}

quint8 Task::getPriority() const
{
    return priority;
}
