#include "teachermain.h"
#include "ui_teachermain.h"

TeacherMain::TeacherMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherMain)
{
    ui->setupUi(this);
}

TeacherMain::~TeacherMain()
{
    delete ui;
}

void TeacherMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void TeacherMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void TeacherMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void TeacherMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void TeacherMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void TeacherMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void TeacherMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void TeacherMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}
