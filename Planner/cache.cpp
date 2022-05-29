#include "cache.h"
#include "currentuser.h"
#include <fstream>
#include <iostream>

#define SETTINGS_CACHE "cache\\settings.txt"
#define TEACHERS_CACHE "cache\\teachers.txt"
#define SUBJECTS_CACHE "cache\\subjects.txt"
#define AGENDA_CACHE "cache\\agenda.txt"
#define GRADES_CACHE "cache\\grades.txt"

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
    std::vector<Teacher> teachers;
    std::ifstream file(TEACHERS_CACHE);
    if(file.is_open())
    {
        Teacher teacher;
        while (file)
        {
            file >> teacher;
            if(teacher.getFullname() != "  ")
            {
                teachers.push_back(teacher);
            }
        }
    }
    return teachers;
}

void Cache::writeTeachers(std::vector<Teacher> teachers)
{
    std::ofstream file(TEACHERS_CACHE);
    if (file.is_open())
    {
        for(Teacher teacher : teachers)
        {
            file << teacher << '\n';
        }
        file.close();
    }
}

void Cache::deleteTeachers()
{

}

std::vector<Subject> Cache::readSubjects()
{
    std::vector<Subject> subjects;
    std::ifstream file(SUBJECTS_CACHE);
    if(file.is_open())
    {
        Subject subject;
        while (file)
        {
            file >> subject;
            if(subject.getName() != "")
            {
                subjects.push_back(subject);
            }
        }
    }
    return subjects;
}

void Cache::writeSubjects(std::vector<Subject> subjects)
{
    std::ofstream file(SUBJECTS_CACHE);
    if (file.is_open())
    {
        for(Subject subject : subjects)
        {
            file << subject << '\n';
        }
        file.close();
    }
}

void Cache::deleteSubjects()
{

}

std::vector<Task> Cache::readAgenda()
{
    std::vector<Task> agenda;
    std::ifstream file(AGENDA_CACHE);
    if(file.is_open())
    {
        Task task;
        while (file)
        {
            file >> task;
            if(task.getName() != "")
            {
                agenda.push_back(task);
            }
        }
    }
    return agenda;
}

void Cache::writeAgenda(std::vector<Task> agenda)
{
    std::ofstream file(AGENDA_CACHE);
    if (file.is_open())
    {
        for(Task task : agenda)
        {
            file << task << '\n';
        }
        file.close();
    }
}

void Cache::deleteAgenda()
{

}

std::vector<Grade> Cache::readGrades()
{
    std::vector<Grade> grades;
    std::ifstream file(GRADES_CACHE);
    if(file.is_open())
    {
        Grade grade;
        while (file)
        {
            file >> grade;
            if(grade.getSubject().getName() != "")
            {
                grades.push_back(grade);
            }
        }
    }
    return grades;
}

void Cache::writeGrades(std::vector<Grade> grades)
{
    std::ofstream file(GRADES_CACHE);
    if (file.is_open())
    {
        for(Grade grade : grades)
        {
            file << grade << '\n';
        }
        file.close();
    }
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
    Settings settings;
    if (file.is_open())
    {
        file >> settings;
        file.close();
    }
    return settings;
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
