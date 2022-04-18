#ifndef TEACHER_H
#define TEACHER_H
#include <QString>

class Teacher
{
public:
    Teacher();
    Teacher(QString surname, QString name, QString fathername, QString phone, QString email);

    QString getFullname();
    QString getEmail();
    QString getPhone();

    void setFullname(QString surname, QString name, QString fathername);
    void setPhone(QString phone);
    void setEmail(QString email);

    bool operator>(Teacher anotherTeacher);
    bool operator<(Teacher anotherTeacher);
    bool operator==(Teacher anotherTeacher);
    void operator=(Teacher anotherTeacher);

private:
    QString fullname;
    QString email;
    QString phone;
};

#endif // TEACHER_H
