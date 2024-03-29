#include "teacher.h"

Teacher::Teacher() : fullname("- - -"), email("-"), phone("-")
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
    if(this->fullname == anotherTeacher.fullname)
    {
        return true;
    }
    return false;
}

bool Teacher::operator==(QString anotherTeacherName)
{
    if(this->fullname == anotherTeacherName)
    {
        return true;
    }
    return false;
}

bool Teacher::operator!=(QString anotherTeacherName)
{
    if(this->fullname != anotherTeacherName)
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

std::ostream& operator<<(std::ostream& out, const Teacher& teacher)
{
    out << teacher.fullname.toStdString() << " " << teacher.phone.toStdString() << " " << teacher.email.toStdString();
    return out;
}

std::istream& operator>>(std::istream& in, Teacher& teacher)
{
    std::string name, surname, fathername, phone, email;
    in >> surname >> name >> fathername >> phone >> email;
    teacher.setFullname(QString::fromStdString(surname), QString::fromStdString(name), QString::fromStdString(fathername));
    teacher.setPhone(QString::fromStdString(phone));
    teacher.setEmail(QString::fromStdString(email));
    return in;
}
