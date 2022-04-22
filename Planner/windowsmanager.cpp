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
#include "areyousure.h"

WindowsManager::WindowsManager(QObject *parent) : QObject(parent), mainWindow(nullptr), minorWindow(nullptr), dialogWindow(nullptr)
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

void WindowsManager::close_DialogWindow()
{
    if(dialogWindow)
    {
        dialogWindow->close();
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
    connect(mainWindow.get(), SIGNAL(OpenPlanAdding()), this, SLOT(open_TimetableItemAdding()));
    connect(mainWindow.get(), SIGNAL(OpenClock()), this, SLOT(open_Clock()));
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
    mainWindow.reset(new CalendarMain());
    set_MenuConections();
    mainWindow->show();
}

void WindowsManager::open_AgendaMain()
{
    close_MainWindow();
    mainWindow.reset(new AgendaMain());
    set_MenuConections();
    connect(mainWindow.get(), SIGNAL(OpenAgendaAdding()), this, SLOT(open_AgendaAdding()));
    connect(mainWindow.get(), SIGNAL(OpenEditDeleteOrMarkAsDone()), this, SLOT(open_EditDeleteOrMarkAsDone()));
    mainWindow->show();
}

void WindowsManager::open_AgendaAdding()
{
    minorWindow.reset(new AgendaAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(minorWindow.get(), SIGNAL(OpenPickUpDate()), this, SLOT(open_Calendar()));
    minorWindow->show();
}

void WindowsManager::open_SubjectsMain()
{
    close_MainWindow();
    mainWindow.reset(new SubjectsMain());
    set_MenuConections();
    connect(mainWindow.get(), SIGNAL(OpenSubjectAdding()), this, SLOT(open_SubjectAdding()));
    connect(mainWindow.get(), SIGNAL(OpenSubjectEditing(Subject)), this, SLOT(open_SubjectEditing(Subject)));
    connect(mainWindow.get(), SIGNAL(OpenEditOrDelete()), this, SLOT(open_EditOrDelete()));
    mainWindow->show();
}

void WindowsManager::open_SubjectAdding()
{
    minorWindow.reset(new SubjectAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(minorWindow.get(), SIGNAL(Save(Subject)), mainWindow.get(), SLOT(addSubject(Subject)));
    minorWindow->show();
}

void WindowsManager::open_SubjectEditing(Subject subject)
{
    minorWindow.reset(new SubjectAdding(subject));
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(minorWindow.get(), SIGNAL(Save(Subject)), mainWindow.get(), SLOT(editSubject(Subject)));
    minorWindow->show();
}

void WindowsManager::open_TeachersMain()
{
    close_MainWindow();
    mainWindow.reset(new TeacherMain());
    set_MenuConections();
    connect(mainWindow.get(), SIGNAL(OpenTeacherAdding()), this, SLOT(open_TeacherAdding()));
    connect(mainWindow.get(), SIGNAL(OpenTeacherEditing(Teacher)), this, SLOT(open_TeacherEditing(Teacher)));
    connect(mainWindow.get(), SIGNAL(OpenEditOrDelete()), this, SLOT(open_EditOrDelete()));
    mainWindow->show();
}

void WindowsManager::open_TeacherAdding()
{
    minorWindow.reset(new TeacherAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(minorWindow.get(), SIGNAL(Save(Teacher)), mainWindow.get(), SLOT(addTeacher(Teacher)));
    minorWindow->show();
}

void WindowsManager::open_TeacherEditing(Teacher teacher)
{
    minorWindow.reset(new TeacherAdding(teacher));
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(minorWindow.get(), SIGNAL(Save(Teacher)), mainWindow.get(), SLOT(editTeacher(Teacher)));
    minorWindow->show();
}

void WindowsManager::open_GradesMain()
{
    close_MainWindow();
    mainWindow.reset(new GradesMain());
    set_MenuConections();
    connect(mainWindow.get(), SIGNAL(OpenGradeAdding()), this, SLOT(open_GradeAdding()));
    connect(mainWindow.get(), SIGNAL(OpenGradeEditing(Grade)), this, SLOT(open_GradeEditing(Grade)));
    connect(mainWindow.get(), SIGNAL(OpenEditOrDelete()), this, SLOT(open_EditOrDelete()));
    mainWindow->show();
}

void WindowsManager::open_GradeAdding()
{
    minorWindow.reset(new GradesAdding());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(minorWindow.get(), SIGNAL(OpenPickUpDate()), this, SLOT(open_Calendar()));
    connect(minorWindow.get(), SIGNAL(Save(Grade)), mainWindow.get(), SLOT(addGrade(Grade)));
    minorWindow->show();
}

void WindowsManager::open_GradeEditing(Grade grade)
{
    minorWindow.reset(new GradesAdding(grade));
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(minorWindow.get(), SIGNAL(Save(Grade)), mainWindow.get(), SLOT(editGrade(Grade)));
    connect(minorWindow.get(), SIGNAL(OpenPickUpDate()), this, SLOT(open_Calendar()));
    minorWindow->show();
}

void WindowsManager::open_SettingsMain()
{
    close_MainWindow();
    mainWindow.reset(new SettingsMain());
    set_MenuConections();
    connect(mainWindow.get(), SIGNAL(OpenWelcome()), this, SLOT(open_Welcome()));
    mainWindow->show();
}

void WindowsManager::open_Calendar()
{
    dialogWindow.reset(new Calendar());
    dialogWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(dialogWindow.get(), SIGNAL(SetDate(QString)), minorWindow.get(), SLOT(setDate(QString)));
    dialogWindow->show();
}

void WindowsManager::open_Clock()
{
    dialogWindow.reset(new Clock());
    dialogWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    dialogWindow->show();
}

void WindowsManager::open_EditOrDelete()
{
    minorWindow.reset(new EditOrDeleteDialog());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(minorWindow.get(), SIGNAL(Edit()), mainWindow.get(), SLOT(OpenEditingWindow()));
    connect(minorWindow.get(), SIGNAL(Delete()), this, SLOT(open_AreYouSure()));
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
    dialogWindow.reset(new AddGradeDialog());
    dialogWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    dialogWindow->show();
}

void WindowsManager::open_AreYouSure()
{
    minorWindow.reset(new AreYouSure());
    minorWindow->setWindowModality(Qt::WindowModality::ApplicationModal);
    connect(minorWindow.get(), SIGNAL(Yes()), mainWindow.get(), SLOT(Delete()));
    minorWindow->show();
}

