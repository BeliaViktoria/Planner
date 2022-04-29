#include "plan.h"

Plan::Plan() : day(-1), lesson(-1), subject(), room(""), teacher(), link(""), repeating(NULLTYPE)
{

}

Plan::Plan(int day, int lesson, Subject subject, QString room, Teacher teacher, QString link, WeekType repeating)
{
    this->day = day;
    this->lesson = lesson;
    this->subject = subject;
    this->room = room;
    this->teacher = teacher;
    this->link = link;
    this->repeating = repeating;
}

int Plan::getDay()
{
    return day;
}

int Plan::getLesson()
{
    return lesson;
}

Subject Plan::getSubject()
{
    return subject;
}

QString Plan::getRoom()
{
    return room;
}

Teacher Plan::getTeacher()
{
    return teacher;
}

QString Plan::getLlink()
{
    return link;
}

WeekType Plan::getRepeating()
{
    return repeating;
}

void Plan::setDay(int day)
{
    this->day = day;
}

void Plan::setLesson(int lesson)
{
    this->lesson = lesson;
}

void Plan::setSubject(Subject subject)
{
    this->subject = subject;
}

void Plan::setRoom(QString room)
{
    this->room = room;
}

void Plan::setTeacher(Teacher teacher)
{
    this->teacher = teacher;
}

void Plan::setLink(QString link)
{
    this->link = link;
}

void Plan::setRepeating(WeekType repeating)
{
    this->repeating = repeating;
}

bool Plan::operator>(Plan anotherPlan)
{
    if(this->lesson > anotherPlan.lesson)
    {
        return true;
    }
    else if(this->lesson == anotherPlan.lesson)
    {
        if(this->day > anotherPlan.day)
        {
            return true;
        }
    }
    return false;
}

bool Plan::operator<(Plan anotherPlan)
{
    if(this->lesson < anotherPlan.lesson)
    {
        return true;
    }
    else if(this->lesson == anotherPlan.lesson)
    {
        if(this->day < anotherPlan.day)
        {
            return true;
        }
    }
    return false;
}

bool Plan::operator==(Plan anotherPlan)
{
    if(this->day == anotherPlan.day && this->lesson == anotherPlan.lesson && this->subject == anotherPlan.subject)
    {
        return true;
    }
    return false;
}

void Plan::operator=(Plan anotherPlan)
{
    this->day = anotherPlan.day;
    this->lesson = anotherPlan.lesson;
    this->subject = anotherPlan.subject;
    this->room = anotherPlan.room;
    this->teacher = anotherPlan.teacher;
    this->link = anotherPlan.link;
    this->repeating = anotherPlan.repeating;
}
