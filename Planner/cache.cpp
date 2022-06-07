#include "cache.h"
#include "currentuser.h"
#include <fstream>
#include <iostream>
#include<cstdio>

#define SETTINGS_CACHE "cache\\settings.txt"
#define TEACHERS_CACHE "cache\\teachers.txt"
#define SUBJECTS_CACHE "cache\\subjects.txt"
#define AGENDA_CACHE "cache\\agenda.txt"
#define GRADES_CACHE "cache\\grades.txt"
#define TIMES_CACHE "cache\\times.txt"
#define TIMETABLE_CACHE "cache\\timetable.txt"

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
        for(Teacher& teacher : teachers)
        {
            file << teacher << '\n';
        }
        file.close();
    }
}

void Cache::deleteTeachers()
{
    remove(TEACHERS_CACHE);
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
        for(Subject& subject : subjects)
        {
            file << subject << '\n';
        }
        file.close();
    }
}

void Cache::deleteSubjects()
{
    remove(SUBJECTS_CACHE);
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
        for(Task& task : agenda)
        {
            file << task << '\n';
        }
        file.close();
    }
}

void Cache::deleteAgenda()
{
    remove(AGENDA_CACHE);
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
        for(Grade& grade : grades)
        {
            file << grade << '\n';
        }
        file.close();
    }
}

void Cache::deleteGrades()
{
    remove(GRADES_CACHE);
}

std::multimap<std::pair<int, int>, Plan> Cache::readTimetable()
{
    std::multimap<std::pair<int, int>, Plan> timetable;
    std::ifstream file(TIMETABLE_CACHE);
    if(file.is_open())
    {
        Plan plan;
        while (file)
        {
            file >> plan;
            if(plan.getSubject().getName() != "")
            {
                timetable.emplace(std::make_pair(plan.getLesson(), plan.getDay()), plan);
            }
        }
    }
    return timetable;
}

void Cache::writeTimetable(std::multimap<std::pair<int, int>, Plan> timetable)
{
    std::ofstream file(TIMETABLE_CACHE);
    if (file.is_open())
    {
        for(auto& plan : timetable)
        {
            file << plan.second << '\n';
        }
        file.close();
    }
}

void Cache::deleteTimetable()
{
    remove(TIMETABLE_CACHE);
}

std::map<std::pair<int, int>, QTime> Cache::readTimes()
{
    std::map<std::pair<int, int>, QTime> times;
    std::ifstream file(TIMES_CACHE);
    if(file.is_open())
    {
        int row, column;
        std::string time;
        while (file)
        {
            file >> row >> column >> time;
            if(time != "")
            {
                times.emplace(std::make_pair(row, column), QTime::fromString(QString::fromStdString(time), "hh:mm"));
            }
        }
    }
    return times;
}

void Cache::writeTimes(std::map<std::pair<int, int>, QTime> times)
{
    std::ofstream file(TIMES_CACHE);
    if (file.is_open())
    {
        for(auto& time : times)
        {
            file << time.first.first << " " << time.first.second << " " << time.second.toString("hh:mm").toStdString() << '\n';
        }
        file.close();
    }
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
