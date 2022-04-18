#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include <QWidget>
#include "teacher.h"

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
    void open_TimetableItemAdding();
    void open_CalendarMain();
    void open_AgendaMain();
    void open_AgendaAdding();
    void open_SubjectsMain();
    void open_SubjectAdding();
    void open_TeachersMain();
    void open_TeacherAdding();
    void open_TeacherEditing(Teacher teacher);
    void open_GradesMain();
    void open_GradeAdding();
    void open_SettingsMain();
    void open_Calendar();
    void open_Clock();

    void open_EditOrDelete();
    void open_EditDeleteOrMarkAsDone();
    void open_SaveGrade();
    void open_AreYouSure();

private:
    std::unique_ptr<QWidget> mainWindow;
    std::unique_ptr<QWidget> minorWindow;
    std::unique_ptr<QWidget> dialogWindow;
};

#endif // WINDOWSMANAGER_H
