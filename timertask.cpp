#include <QThread>
#include <QDebug>
#include "timertask.h"

TimerTask::TimerTask(quint8 priority, quint32 microseconds, Task *wakeupTask, QObject *parent) : Task(priority, true, parent)
{
    this->microseconds = microseconds;
    this->wakeupTask = wakeupTask;
    initTask();
}

TimerTask::~TimerTask()
{
    taskThread->exit();
    taskThread->wait();
}

void TimerTask::initTask()
{
    taskThread = new QThread(this);
    wakeupTask->moveToThread(taskThread);
    connect(taskThread, SIGNAL(finished()), wakeupTask, SLOT(deleteLater()));
    connect(this, SIGNAL(wake()), wakeupTask, SLOT(loop()));
    connect(this, SIGNAL(fin()), wakeupTask, SLOT(stop()), Qt::DirectConnection);
    taskThread->start();
}

void TimerTask::work()
{
    static int i = 0;
    qDebug() << "wakeup" << i++;
    emit wake();
    QThread::usleep(microseconds);
}
