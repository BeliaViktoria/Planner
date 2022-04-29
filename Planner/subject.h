#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
#include "teacher.h"
#include "color.h"

class Subject
{
public:
    Subject();
    Subject(QString name, Teacher teachers[3], Color color, int statistic);

    QString getName();
    Teacher* getTeachers();
    Color getColor();
    int getStatistic();

    void setName(QString name);
    void setTeachers(Teacher teachers[3]);
    void setColor(Color color);
    void setStatistic(int statistic);

    bool operator>(Subject anotherSubject);
    bool operator<(Subject anotherSubject);
    bool operator==(Subject anotherSubject);
    void operator=(Subject anotherSubject);


private:
    QString name;
    Teacher teachers[3];
    Color color;
    int statistic;
};

#endif // SUBJECT_H
