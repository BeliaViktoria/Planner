#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <mutex>
#include "teacher.h"
#include "subject.h"
#include "grade.h"
#include "task.h"
#include "plan.h"
#include "settings.h"

#define DAYSCOUNT 6
#define LESSONSCOUNT 8

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
    std::multimap<std::pair<int, int>, Plan>& getTimetable();
    std::map<std::pair<int, int>, QTime>& getTimes();
    Settings& getSettings();

    void setSettings(Settings settings);

private:
    CurrentUser();

    std::vector<Teacher> teachers;
    std::vector<Subject> subjects;
    std::vector<Grade> grades;
    std::vector<Task> agenda;
    std::multimap<std::pair<int, int>, Plan> timetable;
    std::map<std::pair<int, int>, QTime> times;
    Settings settings;

    static CurrentUser* instance;
    static std::mutex mtx;
};

#endif // CURRENTUSER_H
