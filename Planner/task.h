#ifndef TASK_H
#define TASK_H

#include "subject.h"
#include <QDate>

class Task
{
public:
    Task();
    Task(QString name, Subject subject, QDate deadline);

    QString getName();
    Subject getSubject();
    QDate getDeadline();

    void setName(QString name);
    void setSubject(Subject subject);
    void setDeadline(QDate deadline);
    void setFinished(bool status);

    bool isFinished();

    bool operator>(Task anotherTask);
    bool operator<(Task anotherTask);
    bool operator==(Task anotherTask);
    void operator=(Task anotherTask);

private:
    QString name;
    Subject subject;
    QDate deadline;
    bool finished;
};

#endif // TASK_H
