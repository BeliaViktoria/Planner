#include "timetablemain.h"
#include "ui_timetablemain.h"

TimetableMain::TimetableMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimetableMain)
{
    ui->setupUi(this);

    int columnsSize = ui->tableWidget_Timetable->columnCount();
    for(int i = 0; i < columnsSize; i++)
    {
        ui->tableWidget_Timetable->setColumnWidth(i, 124);
    }

    int rowsSize = ui->tableWidget_Timetable->rowCount();
    for(int i = 0; i < rowsSize; i++)
    {
        ui->tableWidget_Timetable->setRowHeight(i, 41);
    }

    columnsSize = ui->tableWidget_Time_1->columnCount();
    for(int i = 0; i < columnsSize; i++)
    {
        ui->tableWidget_Time_1->setColumnWidth(i, 122);
        ui->tableWidget_Time_2->setColumnWidth(i, 122);
    }

    rowsSize = ui->tableWidget_Time_1->rowCount();
    for(int i = 0; i < rowsSize; i++)
    {
        ui->tableWidget_Time_1->setRowHeight(i, 36);
        ui->tableWidget_Time_2->setRowHeight(i, 36);
    }
}

TimetableMain::~TimetableMain()
{
    delete ui;
}

void TimetableMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void TimetableMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void TimetableMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void TimetableMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void TimetableMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void TimetableMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void TimetableMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void TimetableMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}
