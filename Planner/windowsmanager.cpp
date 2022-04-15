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
    open_Welcome_window();
}

WindowsManager::~WindowsManager()
{

}

void WindowsManager::closeMainWindow()
{
    if(mainWindow)
    {
        mainWindow->close();
    }
}

void WindowsManager::closeMinorWindow()
{
    if(minorWindow)
    {
        minorWindow->close();
    }
}

void WindowsManager::open_Welcome_window()
{
    closeMainWindow();
    mainWindow.reset(new WelcomeMain());
    connect(mainWindow.get(), SIGNAL(OpenOverview()), this, SLOT(open_OverviewMain_window()));
    mainWindow->show();
}

void WindowsManager::open_OverviewMain_window()
{
    closeMainWindow();
    closeMinorWindow();
    mainWindow.reset(new OverviewMain());
    mainWindow->show();
}

void WindowsManager::open_TimetableMain_window()
{
    closeMainWindow();
    closeMinorWindow();
    mainWindow.reset(new TimetableMain());
    mainWindow->show();
}

void WindowsManager::open_TimetableItemAdding_window()
{
    minorWindow.reset(new TimetableItemsAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_CalendarMain_window()
{
    closeMainWindow();
    closeMinorWindow();
    mainWindow.reset(new OverviewMain());
    mainWindow->show();
}

void WindowsManager::open_AgendaMain_window()
{
    closeMainWindow();
    closeMinorWindow();
    mainWindow.reset(new AgendaMain());
    mainWindow->show();
}

void WindowsManager::open_AgendaAdding_window()
{
    minorWindow.reset(new AgendaAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_SubjectsMain_window()
{
    closeMainWindow();
    closeMinorWindow();
    mainWindow.reset(new SubjectsMain());
    mainWindow->show();
}

void WindowsManager::open_SubjectAdding_window()
{
    minorWindow.reset(new SubjectAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_TeachersMain_window()
{
    closeMainWindow();
    closeMinorWindow();
    mainWindow.reset(new TeacherMain());
    mainWindow->show();
}

void WindowsManager::open_TeacherAdding_window()
{
    minorWindow.reset(new TeacherAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_GradesMain_window()
{
    closeMainWindow();
    closeMinorWindow();
    mainWindow.reset(new GradesMain());
    mainWindow->show();
}

void WindowsManager::open_GradeAdding_window()
{
    minorWindow.reset(new GradesAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_SettingsMain_window()
{
    closeMainWindow();
    closeMinorWindow();
    mainWindow.reset(new SettingsMain());
    mainWindow->show();
}

void WindowsManager::open_Calendar_window()
{
    minorWindow.reset(new Calendar());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_Clock_window()
{
    minorWindow.reset(new Clock());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_EditOrDelete_dialog()
{
    minorWindow.reset(new EditOrDeleteDialog());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_EditDeleteOrMarkAsDone_dialog()
{
    minorWindow.reset(new EditDeleteMarkAsDomeDialog());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

void WindowsManager::open_SaveGrade_dialog()
{
    minorWindow.reset(new AddGradeDialog());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    minorWindow->show();
}

