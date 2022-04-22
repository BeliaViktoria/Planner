#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <mutex>
#include <vector>
#include "teacher.h"
#include "subject.h"
#include "grade.h"
#include "task.h"

class CurrentUser
{
public:
    CurrentUser(CurrentUser& other) = delete;
    void operator=(const CurrentUser& other) = delete;

    static CurrentUser* getInstance();

    std::vector<Teacher>& getTeachers();
    std::vector<Subject>& getSubjects();
    std::vector<Grade>& getGrades();
    std::vector<Task>& getAgenda();

private:
    CurrentUser();

    std::vector<Teacher> teachers;
    std::vector<Subject> subjects;
    std::vector<Grade> grades;
    std::vector<Task> agenda;

    static CurrentUser* instance;
    static std::mutex mtx;
};

#endif // CURRENTUSER_H
