#include <QThread>
#include "starter.h"
#include "timertask.h"

Starter::Starter(QObject *parent) : QObject(parent)
{
}

Starter::~Starter()
{
    for(auto thread:threads)
    {
        thread->exit();
    }
    for(auto thread:threads)
    {
        thread->wait();
    }
}

void Starter::initialOne(quint8 priorityTimer, quint8 priorityTask, quint32 cycleTime)
{
    Task *task = new Task(priorityTask, false);
    TimerTask *timerTask = new TimerTask(priorityTimer, cycleTime, task);
    QThread *taskThread = new QThread(this);

    timerTask->moveToThread(taskThread);

    connect(taskThread, SIGNAL(finished()), timerTask, SLOT(deleteLater()));

    connect(this, SIGNAL(wake()), timerTask, SLOT(loop()));
    connect(this, SIGNAL(fin()), timerTask, SLOT(stop()), Qt::DirectConnection);

    taskThread->start();

    threads.append(taskThread);
}

void Starter::initialAll()
{
    initialOne(0, 10, 500000);
}

void Starter::start()
{
    initialAll();
    emit wake();
    return;
}

void Starter::stop()
{
    emit fin();
}
