#ifndef CACHE_H
#define CACHE_H

#define FOLDER_PATH ""
#define TEACHERS_PATH ""
#define SUBJECTS_PATH ""
#define AGENDA_PATH ""
#define GRADES_PATH ""
#define TIMETABLE_PATH ""
#define SETTINGS_PATH ""

#include "teacher.h"
#include "subject.h"
#include "grade.h"
#include "task.h"
#include "plan.h"
#include "settings.h"

class Cache
{
public:
    Cache();

    bool static exist();
    std::vector<Teacher> static readTeachers();
    void static writeTeachers(std::vector<Teacher> teachers);
    void static deleteTeachers();
    std::vector<Subject> static readSubjects();
    void static writeSubjects(std::vector<Subject> subjects);
    void static deleteSubjects();
    std::vector<Task> static readAgenda();
    void static writeAgenda(std::vector<Task> agenda);
    void static deleteAgenda();
    std::vector<Grade> static readGrades();
    void static writeGrades(std::vector<Grade> grades);
    void static deleteGrades();
    std::multimap<std::pair<int, int>, Plan> static readTimetable();
    void static writeTimetable(std::multimap<std::pair<int, int>, Plan> timetable);
    void static deleteTimetable();
    std::map<std::pair<int, int>, QTime> static readTimes();
    void static writeTimes(std::map<std::pair<int, int>, QTime> times);
    Settings static readSettings();
    void static writeSettings(Settings settings);
    void static deleteSettings();
};

#endif // CACHE_H
