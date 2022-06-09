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
    bool operator==(QString anotherTeacherName);
    bool operator!=(QString anotherTeacherName);
    void operator=(Teacher anotherTeacher);

    friend std::ostream& operator<<(std::ostream& out, const Teacher& teacher);
    friend std::istream& operator>>(std::istream& in, Teacher& teacher);

private:
    QString fullname;
    QString email;
    QString phone;
};

#endif // TEACHER_H
