#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include <QWidget>
#include "teacher.h"
#include "subject.h"
#include "grade.h"
#include "task.h"
#include "plan.h"

class WindowsManager : public QObject
{
    Q_OBJECT

public:
    explicit WindowsManager(QObject *parent = nullptr);
    ~WindowsManager();

private:
    void set_MenuConections();

private slots:
    void close_MainWindow();
    void close_MinorWindow();
    void close_DialogWindow();

    void open_Welcome();
    void open_OverviewMain();
    void open_TimetableMain();
    void open_TimetableItemAdding(int lesson, int day);
    void open_TimetableItemEditing(Plan plan);
    void open_CalendarMain();
    void open_AgendaMain();
    void open_AgendaAdding();
    void open_AgendaEditing(Task task);
    void open_SubjectsMain();
    void open_SubjectAdding();
    void open_SubjectEditing(Subject);
    void open_TeachersMain();
    void open_TeacherAdding();
    void open_TeacherEditing(Teacher teacher);
    void open_GradesMain();
    void open_GradeAdding();
    void open_GradeEditing(Grade grade);
    void open_SettingsMain();
    void open_Calendar();
    void open_Clock();

    void open_EditOrDelete();
    void open_EditDeleteOrMarkAsDone(bool taskStatus);
    void open_AreYouSure();

private:
    std::unique_ptr<QWidget> mainWindow;
    std::unique_ptr<QWidget> minorWindow;
    std::unique_ptr<QWidget> dialogWindow;
};

#endif // WINDOWSMANAGER_H
