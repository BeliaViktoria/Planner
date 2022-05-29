#include "task.h"

Task::Task() : name(""), subject(), deadline(), finished(false)
{

}

Task::Task(QString name, Subject subject, QDate deadline)
{
    this->name = name;
    this->subject = subject;
    this->deadline = deadline;
    this->finished = false;
}

QString Task::getName()
{
    return name;
}

Subject Task::getSubject()
{
    return subject;
}

QDate Task::getDeadline()
{
    return deadline;
}

void Task::setName(QString name)
{
    this->name = name;
}

void Task::setSubject(Subject subject)
{
    this->subject = subject;
}

void Task::setDeadline(QDate deadline)
{
    this->deadline = deadline;
}

void Task::setFinished(bool status)
{
    this->finished = status;
}

bool Task::isFinished()
{
    return finished;
}

bool Task::operator>(Task anotherTask)
{
    if(this->deadline > anotherTask.deadline)
    {
        return true;
    }
    else if(this->deadline == anotherTask.deadline)
    {
        if(this->subject.getName() > subject.getName())
        {
            return true;
        }
        else if(this->subject.getName() == anotherTask.subject.getName())
        {
            if(this->name > anotherTask.name)
            {
                return true;
            }
        }
    }
    return false;
}

bool Task::operator<(Task anotherTask)
{
    if(this->deadline < anotherTask.deadline)
    {
        return true;
    }
    else if(this->deadline == anotherTask.deadline)
    {   
        if(this->subject.getName() < subject.getName())
        {
            return true;
        }
        else if(this->subject.getName() == anotherTask.subject.getName())
        {
            if(this->name < anotherTask.name)
            {
                return true;
            }
        }
    }
    return false;
}

bool Task::operator==(Task anotherTask)
{
    if(this->name == anotherTask.name && this->subject == anotherTask.subject)
    {
        return true;
    }
    return false;
}

void Task::operator=(Task anotherTask)
{
    this->name = anotherTask.name;
    this->subject = anotherTask.subject;
    this->deadline = anotherTask.deadline;
    this->finished = anotherTask.finished;
}

std::ostream& operator<<(std::ostream& out, const Task& task)
{
    out << task.name.toStdString() << "\n" << task.subject << " " << task.deadline.toString("dd.MM.yyyy").toStdString() << " " << task.finished;
    return out;
}

std::istream& operator>>(std::istream& in, Task& task)
{
    std::string name, deadline;
    std::getline(in, name);
    if(name == "")
    {
        std::getline(in, name);
    }
    in >> task.subject >> deadline >> task.finished;
    task.setName(QString::fromStdString(name));
    task.setDeadline(QDate::fromString(QString::fromStdString(deadline), "dd.MM.yyyy"));
    return in;
}
