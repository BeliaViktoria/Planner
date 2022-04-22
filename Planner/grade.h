#ifndef GRADE_H
#define GRADE_H

#include "subject.h"
#include <QDate>

class Grade
{
public:
    Grade();
    Grade(int currentGrade, int maxGrade, Subject subject, QDate date, QString note);
    
    int getCurrentGrade();
    int getMaxGrade();
    Subject getSubject();
    QDate getDate();
    QString getNote();

    void setCurrentGrade(int currentGrade);
    void setMaxGrade(int maxGrade);
    void setSubject(Subject subject);
    void setDate(QDate date);
    void setNote(QString note);

    bool operator>(Grade anotherGrade);
    bool operator<(Grade anotherGrade);
    bool operator==(Grade anotherGrade);
    void operator=(Grade anotherGrade);
    
private:
    int currentGrade;
    int maxGrade;
    Subject subject;
    QDate date;
    QString note;
};

#endif // GRADE_H
