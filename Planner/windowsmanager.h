#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include <QObject>
#include <QWidget>

class WindowsManager : public QObject
{
    Q_OBJECT

    std::unique_ptr<QWidget> mainWindow;
    std::unique_ptr<QWidget> minorWindow;
public:
    explicit WindowsManager(QObject *parent = nullptr);
    ~WindowsManager();

private slots:
    void closeMainWindow();
    void closeMinorWindow();

    void open_Welcome_window();
    void open_OverviewMain_window();
    void open_TimetableMain_window();
    void open_TimetableItemAdding_window();
    void open_CalendarMain_window();
    void open_AgendaMain_window();
    void open_AgendaAdding_window();
    void open_SubjectsMain_window();
    void open_SubjectAdding_window();
    void open_TeachersMain_window();
    void open_TeacherAdding_window();
    void open_GradesMain_window();
    void open_GradeAdding_window();
    void open_SettingsMain_window();
    void open_Calendar_window();
    void open_Clock_window();

    void open_EditOrDelete_dialog();
    void open_EditDeleteOrMarkAsDone_dialog();
    void open_SaveGrade_dialog();

signals:

};

#endif // WINDOWSMANAGER_H
