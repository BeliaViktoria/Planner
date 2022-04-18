#include "teacher.h"

Teacher::Teacher() : fullname(""), email(""), phone("")
{

}

Teacher::Teacher(QString surname, QString name, QString fathername, QString phone, QString email)
{
    fullname = surname + ' ' + name + ' ' + fathername;
    this->email = email;
    this->phone = phone;
}

QString Teacher::getFullname()
{
    return fullname;
}

QString Teacher::getEmail()
{
    return email;
}

QString Teacher::getPhone()
{
    return phone;
}

void Teacher::setFullname(QString surname, QString name, QString fathername)
{
    fullname = surname + ' ' + name + ' ' + fathername;
}

void Teacher::setPhone(QString phone)
{
    this->phone = phone;
}

void Teacher::setEmail(QString email)
{
    this->email = email;
}

bool Teacher::operator>(Teacher anotherTeacher)
{
    if(this->fullname > anotherTeacher.fullname)
    {
        return true;
    }
    return false;
}

bool Teacher::operator<(Teacher anotherTeacher)
{
    if(this->fullname < anotherTeacher.fullname)
    {
        return true;
    }
    return false;
}

bool Teacher::operator==(Teacher anotherTeacher)
{
    if(this->fullname == anotherTeacher.fullname && this->phone == anotherTeacher.phone && this->email == anotherTeacher.email)
    {
        return true;
    }
    return false;
}

void Teacher::operator=(Teacher anotherTeacher)
{
    this->fullname = anotherTeacher.fullname;
    this->phone = anotherTeacher.phone;
    this->email = anotherTeacher.email;
}
