#include "subject.h"

Subject::Subject() : name(""), teachers{Teacher(), Teacher(), Teacher()}, color()
{

}

Subject::Subject(QString name, Teacher teachers[3], Color color)
{
    this->name = name;
    this->color = color;
    for(int i = 0; i < 3; i++)
    {
        this->teachers[i] = teachers[i];
    }
}

QString Subject::getName()
{
    return name;
}

Teacher* Subject::getTeachers()
{
    return teachers;
}

Color Subject::getColor()
{
    return color;
}

void Subject::setName(QString name)
{
    this->name = name;
}

void Subject::setTeachers(Teacher teachers[3])
{
    for(int i = 0; i < 3; i++)
    {
        this->teachers[i] = teachers[i];
    }
}
void Subject::setColor(Color color)
{
    this->color = color;
}

bool Subject::operator>(Subject anotherSubject)
{
    if(this->name > anotherSubject.name)
    {
        return true;
    }
    return false;
}

bool Subject::operator<(Subject anotherSubject)
{
    if(this->name < anotherSubject.name)
    {
        return true;
    }
    return false;
}

bool Subject::operator==(Subject anotherSubject)
{
    if(this->name == anotherSubject.name)
    {
        return true;
    }
    return false;
}

void Subject::operator=(Subject anotherSubject)
{
    this->name = anotherSubject.name;
    this->color = anotherSubject.color;
    for(int i = 0; i < 3; i++)
    {
        this->teachers[i] = anotherSubject.teachers[i];
    }
}
