#include "grade.h"

Grade::Grade() : currentGrade(0), maxGrade(0), subject(), date(), note()
{

}

Grade::Grade(int currentGrade, int maxGrade, Subject subject, QDate date, QString note)
{
    this->currentGrade = currentGrade;
    this->maxGrade = maxGrade;
    this->subject = subject;
    this->date = date;
    this->note = note;
}

int Grade::getCurrentGrade()
{
    return currentGrade;
}

int Grade::getMaxGrade()
{
    return maxGrade;
}

Subject Grade::getSubject()
{
    return subject;
}

QDate Grade::getDate()
{
    return date;
}

QString Grade::getNote()
{
    return note;
}

void Grade::setCurrentGrade(int currentGrade)
{
    this->currentGrade = currentGrade;
}

void Grade::setMaxGrade(int maxGrade)
{
    this->maxGrade = maxGrade;
}

void Grade::setSubject(Subject subject)
{
    this->subject = subject;
}

void Grade::setDate(QDate date)
{
    this->date = date;
}

void Grade::setNote(QString note)
{
    this->note = note;
}

bool Grade::operator>(Grade anotherGrade)
{
    if(this->subject > anotherGrade.subject)
    {
        return true;
    }
    if(this->subject == anotherGrade.subject)
    {
        if(this->date > anotherGrade.date)
        {
            return true;
        }
    }
    return false;
}

bool Grade::operator<(Grade anotherGrade)
{
    if(this->subject < anotherGrade.subject)
    {
        return true;
    }
    if(this->subject == anotherGrade.subject)
    {
        if(this->date < anotherGrade.date)
        {
            return true;
        }
    }
    return false;
}

bool Grade::operator==(Grade anotherGrade)
{
    if(this->subject == anotherGrade.subject && this->currentGrade == anotherGrade.currentGrade)
    {
        return true;
    }
    return false;
}

void Grade::operator=(Grade anotherGrade)
{
    this->currentGrade = anotherGrade.currentGrade;
    this->maxGrade = anotherGrade.maxGrade;
    this->subject = anotherGrade.subject;
    this->date = anotherGrade.date;
    this->note = anotherGrade.note;
}
