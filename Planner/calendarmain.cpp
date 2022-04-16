#include "calendarmain.h"
#include "ui_calendarmain.h"

CalendarMain::CalendarMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarMain)
{
    ui->setupUi(this);
}

CalendarMain::~CalendarMain()
{
    delete ui;
}

void CalendarMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void CalendarMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void CalendarMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void CalendarMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void CalendarMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void CalendarMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void CalendarMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void CalendarMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}
