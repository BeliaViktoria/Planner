#ifndef PLAN_H
#define PLAN_H

#include "subject.h"
#include "teacher.h"
#include "settings.h"

class Plan
{
public:
    Plan();
    Plan(int day, int lesson, Subject subject, int room, Teacher teacher, QString link, WeekType repeating);

    int getDay();
    int getLesson();
    Subject getSubject();
    int getRoom();
    Teacher getTeacher();
    QString getLlink();
    WeekType getRepeating();

    void setDay(int day);
    void setLesson(int lesson);
    void setSubject(Subject subject);
    void setRoom(int room);
    void setTeacher(Teacher teacher);
    void setLink(QString link);
    void setRepeating(WeekType repeating);

    bool operator>(Plan anotherPlan);
    bool operator<(Plan anotherPlan);
    bool operator==(Plan anotherPlan);
    void operator=(Plan anotherPlan);

private:
    int day;
    int lesson;
    Subject subject;
    int room;
    Teacher teacher;
    QString link;
    WeekType repeating;
};

#endif // PLAN_H
