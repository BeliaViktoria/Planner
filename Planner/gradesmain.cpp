#include "gradesmain.h"
#include "ui_gradesmain.h"

GradesMain::GradesMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradesMain)
{
    ui->setupUi(this);
}

GradesMain::~GradesMain()
{
    delete ui;
}

void GradesMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void GradesMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void GradesMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void GradesMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void GradesMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void GradesMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void GradesMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void GradesMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}
