#ifndef STARTER_H
#define STARTER_H

#include <QObject>

class Task;
class TimerTask;

class Starter : public QObject
{
    Q_OBJECT
public:
    explicit Starter(QObject *parent = 0);
    ~Starter();
    void start();
    void stop();

signals:
    void wake();
    void fin();

public slots:

private:
    Task* task;
    TimerTask* timerTask;
    QThread* taskThread;
};

#endif // STARTER_H
