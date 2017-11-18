#ifndef STARTER_H
#define STARTER_H

#include <QObject>

class Starter : public QObject
{
    Q_OBJECT
public:
    explicit Starter(QObject *parent = 0);
    ~Starter();
    void start();
    void stop();

private:
    void initialOne(quint8 priorityTimer, quint8 priorityTask, quint32 cycleTime);
    void initialAll();

signals:
    void wake();
    void fin();

public slots:

private:
    QList<QThread*> threads;
};

#endif // STARTER_H
