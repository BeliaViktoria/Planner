#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
#include "teacher.h"
#include "color.h"

class Subject
{
public:
    Subject();
    Subject(QString name, Teacher teachers[3], Color color);

    QString getName();
    Teacher* getTeachers();
    Color getColor();

    void setName(QString name);
    void setTeachers(Teacher teachers[3]);
    void setColor(Color color);

    bool operator>(Subject anotherSubject);
    bool operator<(Subject anotherSubject);
    bool operator==(Subject anotherSubject);
    void operator=(Subject anotherSubject);


private:
    QString name;
    Teacher teachers[3];
    Color color;
};

#endif // SUBJECT_H