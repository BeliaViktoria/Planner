#include "agendamain.h"
#include "ui_agendamain.h"

AgendaMain::AgendaMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgendaMain)
{
    ui->setupUi(this);
}

AgendaMain::~AgendaMain()
{
    delete ui;
}

void AgendaMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void AgendaMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void AgendaMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void AgendaMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void AgendaMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void AgendaMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void AgendaMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void AgendaMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}

void AgendaMain::on_pushButton_AddTask_clicked()
{
    emit OpenAgendaAdding();
}

void AgendaMain::on_listWidget_Tasks_itemClicked(QListWidgetItem *item)
{
    emit OpenEditDeleteOrMarkAsDone();
}

