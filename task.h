#ifndef TASK_H
#define TASK_H

#include <QObject>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(quint8 priority, bool ever = true, QObject *parent = 0);

    quint8 getPriority() const;

protected:
    virtual void work();

signals:
    void wake();
    void fin();

public slots:
    void loop();
    void stop();

private:
    quint8 priority;
    bool ever;
};

#endif // TASK_H
