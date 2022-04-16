#include "subjectsmain.h"
#include "ui_subjectsmain.h"

SubjectsMain::SubjectsMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectsMain)
{
    ui->setupUi(this);
}

SubjectsMain::~SubjectsMain()
{
    delete ui;
}

void SubjectsMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void SubjectsMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void SubjectsMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void SubjectsMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void SubjectsMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void SubjectsMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void SubjectsMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void SubjectsMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}
