#include "timetablemain.h"
#include "ui_timetablemain.h"
#include "currentuser.h"

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
        ui->tableWidget_Timetable->setRowHeight(i, 39);
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

    switch(CurrentUser::getInstance()->getSettings().getStartFrom())
    {
    case NUMERATOR:
        if(QDate::currentDate().weekNumber() % 2 == CurrentUser::getInstance()->getSettings().getStartDate().weekNumber() % 2)
        {
            ui->label_ThisWeek->setText("This week: numerator");
            ui->radioButton_Numerator->setChecked(true);
        }
        else
        {
            ui->label_ThisWeek->setText("This week: denominator");
            ui->radioButton_Denominator->setChecked(true);
        }
        break;
    case DENOMINATOR:
        if(QDate::currentDate().weekNumber() % 2 == CurrentUser::getInstance()->getSettings().getStartDate().weekNumber() % 2)
        {
            ui->label_ThisWeek->setText("This week: denominator");
            ui->radioButton_Denominator->setChecked(true);
        }
        else
        {
            ui->label_ThisWeek->setText("This week: numerator");
            ui->radioButton_Numerator->setChecked(true);
        }
        break;
    case NULLTYPE:
        ui->label_ThisWeek->hide();
        ui->radioButton_Numerator->hide();
        ui->radioButton_Denominator->hide();
        break;
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
void TimetableMain::on_tableWidget_Timetable_cellClicked(int row, int column)
{
    if(ui->tableWidget_Timetable->item(row, column)->text() == "")
    {
        emit OpenPlanAdding(row, column);
    }
    else
    {
        emit OpenEditOrDelete();
    }
}

void TimetableMain::on_tableWidget_Time_1_cellClicked(int row, int column)
{
    emit OpenClock();
}

void TimetableMain::on_tableWidget_Time_2_cellClicked(int row, int column)
{
    emit OpenClock();
}

void TimetableMain::OpenEditingWindow()
{
    int row = ui->tableWidget_Timetable->currentRow();
    int column = ui->tableWidget_Timetable->currentColumn();
    auto iterator = CurrentUser::getInstance()->getTimetable().find(std::make_pair(row, column));
    // check whether it is numerator
    emit OpenPlanEditing((*iterator).second);
}

void TimetableMain::editPlan(Plan plan)
{

}

void TimetableMain::Delete()
{

}

void TimetableMain::addPlan(Plan plan)
{

}

