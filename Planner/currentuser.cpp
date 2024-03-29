#include "currentuser.h"

CurrentUser* CurrentUser::instance{nullptr};
std::mutex CurrentUser::mtx;

CurrentUser::CurrentUser(){}

CurrentUser* CurrentUser::getInstance()
{
    std::lock_guard<std::mutex> lock(mtx);
    if(instance == nullptr)
    {
        instance = new CurrentUser();
    }
    return instance;
}

std::vector<Teacher>& CurrentUser::getTeachers()
{
    return teachers;
}

std::vector<Subject>& CurrentUser::getSubjects()
{
    return subjects;
}

std::vector<Grade>& CurrentUser::getGrades()
{
    return grades;
}

std::vector<Task>& CurrentUser::getAgenda()
{
    return agenda;
}

std::multimap<std::pair<int, int>, Plan>& CurrentUser::getTimetable()
{
    return timetable;
}

Settings& CurrentUser::getSettings()
{
    return settings;
}

std::map<std::pair<int, int>, QTime>& CurrentUser::getTimes()
{
    return times;
}

void CurrentUser::setSettings(Settings settings)
{
    this->settings = settings;
}
