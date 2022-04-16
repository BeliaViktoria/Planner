#include "settingsmain.h"
#include "ui_settingsmain.h"

SettingsMain::SettingsMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsMain)
{
    ui->setupUi(this);
}

SettingsMain::~SettingsMain()
{
    delete ui;
}

void SettingsMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void SettingsMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void SettingsMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void SettingsMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void SettingsMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void SettingsMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void SettingsMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void SettingsMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}
