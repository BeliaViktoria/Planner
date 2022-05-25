#include "cache.h"
#include "currentuser.h"
#include <fstream>
#include <iostream>

#define SETTINGS_CACHE "cache\\settings.txt"

Cache::Cache()
{

}

bool Cache::exist()
{
    std::ifstream file(SETTINGS_CACHE);
    if (file.is_open())
    {
        file.close();
        return true;
    }
    return false;
}

std::vector<Teacher> Cache::readTeachers()
{

}

void Cache::writeTeachers(std::vector<Teacher> teachers)
{

}

void Cache::deleteTeachers()
{

}

std::vector<Subject> Cache::readSubjects()
{

}

void Cache::writeSubjects(std::vector<Subject> subjects)
{

}

void Cache::deleteSubjects()
{

}

std::vector<Task> Cache::readAgenda()
{

}

void Cache::writeAgenda(std::vector<Task> agenda)
{

}

void Cache::deleteAgenda()
{

}

std::vector<Grade> Cache::readGrades()
{

}

void Cache::writeGrades(std::vector<Grade> grades)
{

}

void Cache::deleteGrades()
{

}

std::multimap<std::pair<int, int>, Plan> Cache::readTimetable()
{

}

void Cache::writeTimetable(std::multimap<std::pair<int, int>, Plan> timetable)
{

}

void Cache::deleteTimetable()
{

}

std::map<std::pair<int, int>, QTime> Cache::readTimes()
{

}

void Cache::writeTimes(std::map<std::pair<int, int>, QTime> times)
{

}

Settings Cache::readSettings()
{
    std::ifstream file(SETTINGS_CACHE);
    if (file.is_open())
    {
        file >> CurrentUser::getInstance()->getSettings();
        file.close();
    }
}

void Cache::writeSettings(Settings settings)
{
    std::ofstream file(SETTINGS_CACHE);
    if (file.is_open())
    {
        file << settings;
        file.close();
    }
}

void Cache::deleteSettings()
{

}
