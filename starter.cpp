#include <QThread>
#include "starter.h"
#include "timerTask.h"

Starter::Starter(QObject *parent) : QObject(parent),
    task(new Task(1, false)),
    timerTask(new TimerTask(0, 500000, task)),
    taskThread(new QThread(this))
{
    timerTask->moveToThread(taskThread);

    connect(taskThread, SIGNAL(finished()), timerTask, SLOT(deleteLater()));

    connect(this, SIGNAL(wake()), timerTask, SLOT(loop()));
    connect(this, SIGNAL(fin()), timerTask, SLOT(stop()), Qt::DirectConnection);

    taskThread->start();
}

Starter::~Starter()
{
    taskThread->exit();
    taskThread->wait();
}

void Starter::start()
{
    emit wake();
    return;
}

void Starter::stop()
{
    emit fin();
}
