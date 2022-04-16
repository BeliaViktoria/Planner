#include "overviewmain.h"
#include "ui_overviewmain.h"

OverviewMain::OverviewMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverviewMain)
{
    ui->setupUi(this);
}

OverviewMain::~OverviewMain()
{
    delete ui;
}

void OverviewMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void OverviewMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void OverviewMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void OverviewMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void OverviewMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void OverviewMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void OverviewMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void OverviewMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}

