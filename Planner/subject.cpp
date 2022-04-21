#include "subject.h"

Color::Color() : color(), colorName("")
{

}

Color::Color(QColor color, QString colorName)
{
    this->color = color;
    this->colorName = colorName;
}

QString Color::getColorName()
{
    return colorName;
}

QColor Color::getColor()
{
    return color;
}

void Color::setColorName(QString colorName)
{
    this->colorName = colorName;
}

void Color::setColor(QColor color)
{
    this->color = color;
}

bool Color::operator==(Color anotherColor)
{
    if(colorName == anotherColor.colorName && color == anotherColor.color)
    {
        return true;
    }
    return false;
}

void Color::operator=(Color anotherColor)
{
    this->color = anotherColor.color;
    this->colorName = anotherColor.colorName;
}

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
