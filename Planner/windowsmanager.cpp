#include "windowsmanager.h"
#include "welcomemain.h"
#include "overviewmain.h"
#include "timetablemain.h"
#include "timetableitemsadding.h"
#include "calendarmain.h"
#include "agendamain.h"
#include "agendaadding.h"
#include "subjectsmain.h"
#include "subjectadding.h"
#include "teachermain.h"
#include "teacheradding.h"
#include "gradesmain.h"
#include "gradesadding.h"
#include "settingsmain.h"
#include "calendar.h"
#include "clock.h"
#include "editordeletedialog.h"
#include "editdeletemarkasdomedialog.h"
#include "addgradedialog.h"

WindowsManager::WindowsManager(QObject *parent) : QObject(parent), mainWindow(nullptr), minorWindow(nullptr)
{
    open_Welcome();
}

WindowsManager::~WindowsManager()
{

}

void WindowsManager::set_MenuConections()
{
    connect(mainWindow.get(), SIGNAL(OpenOverview()), this, SLOT(open_OverviewMain()));
    connect(mainWindow.get(), SIGNAL(OpenTimetable()), this, SLOT(open_TimetableMain()));
    connect(mainWindow.get(), SIGNAL(OpenCalendar()), this, SLOT(open_CalendarMain()));
    connect(mainWindow.get(), SIGNAL(OpenAgenda()), this, SLOT(open_AgendaMain()));
    connect(mainWindow.get(), SIGNAL(OpenSubjects()), this, SLOT(open_SubjectsMain()));
    connect(mainWindow.get(), SIGNAL(OpenTeachers()), this, SLOT(open_TeachersMain()));
    connect(mainWindow.get(), SIGNAL(OpenGrades()), this, SLOT(open_GradesMain()));
    connect(mainWindow.get(), SIGNAL(OpenSettings()), this, SLOT(open_SettingsMain()));
}

void WindowsManager::close_MainWindow()
{
    if(mainWindow)
    {
        mainWindow->close();
    }
}

void WindowsManager::close_MinorWindow()
{
    if(minorWindow)
    {
        minorWindow->close();
        minorWindow.reset(nullptr);
    }
}

void WindowsManager::open_Welcome()
{
    close_MainWindow();
    mainWindow.reset(new WelcomeMain());
    connect(mainWindow.get(), SIGNAL(OpenOverview()), this, SLOT(open_OverviewMain()));
    mainWindow->show();
}

void WindowsManager::open_OverviewMain()
{
    close_MainWindow();
    mainWindow.reset(new OverviewMain());
    set_MenuConections();
    mainWindow->show();
}

void WindowsManager::open_TimetableMain()
{
    close_MainWindow();
    mainWindow.reset(new TimetableMain());
    set_MenuConections();
    mainWindow->show();
}

void WindowsManager::open_TimetableItemAdding()
{
    minorWindow.reset(new TimetableItemsAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_CalendarMain()
{
    close_MainWindow();
    mainWindow.reset(new OverviewMain());
    set_MenuConections();
    mainWindow->show();
}

void WindowsManager::open_AgendaMain()
{
    close_MainWindow();
    mainWindow.reset(new AgendaMain());
    set_MenuConections();
    mainWindow->show();
}

void WindowsManager::open_AgendaAdding()
{
    minorWindow.reset(new AgendaAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_SubjectsMain()
{
    close_MainWindow();
    mainWindow.reset(new SubjectsMain());
    set_MenuConections();
    mainWindow->show();
}

void WindowsManager::open_SubjectAdding()
{
    minorWindow.reset(new SubjectAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_TeachersMain()
{
    close_MainWindow();
    mainWindow.reset(new TeacherMain());
    set_MenuConections();
    mainWindow->show();
}

void WindowsManager::open_TeacherAdding()
{
    minorWindow.reset(new TeacherAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_GradesMain()
{
    close_MainWindow();
    mainWindow.reset(new GradesMain());
    set_MenuConections();
    mainWindow->show();
}

void WindowsManager::open_GradeAdding()
{
    minorWindow.reset(new GradesAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_SettingsMain()
{
    close_MainWindow();
    mainWindow.reset(new SettingsMain());
    set_MenuConections();
    mainWindow->show();
}

void WindowsManager::open_Calendar()
{
    minorWindow.reset(new Calendar());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_Clock()
{
    minorWindow.reset(new Clock());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_EditOrDelete()
{
    minorWindow.reset(new EditOrDeleteDialog());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_EditDeleteOrMarkAsDone()
{
    minorWindow.reset(new EditDeleteMarkAsDomeDialog());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_SaveGrade()
{
    minorWindow.reset(new AddGradeDialog());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

