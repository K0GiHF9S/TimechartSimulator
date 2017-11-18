#ifndef TIMERTASK_H
#define TIMERTASK_H

#include <QObject>
#include "task.h"

class TimerTask : public Task
{
    Q_OBJECT
public:
    explicit TimerTask(quint8 priority, quint32 microseconds, Task *wakeupTask, QObject *parent = 0);
    ~TimerTask();

protected:
    virtual void work();

private:
    void initTask();

signals:

public slots:

private:
    quint32 microseconds;
    Task *wakeupTask;
    QThread* taskThread;
};

#endif // TIMERTASK_H
