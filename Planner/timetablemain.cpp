#include "timetablemain.h"
#include "ui_timetablemain.h"
#include "currentuser.h"

TimetableMain::TimetableMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimetableMain)
{
    ui->setupUi(this);
    setTablesSize();
    setWeekType();
    showTimetable();
}

TimetableMain::~TimetableMain()
{
    timetable.clear();
    ui->tableWidget_Timetable->clear();
    delete ui;
}

void TimetableMain::setWeekType()
{
    switch(CurrentUser::getInstance()->getSettings().getStartFrom())
    {
    case NUMERATOR:
        if(QDate::currentDate().weekNumber() % 2 == CurrentUser::getInstance()->getSettings().getStartDate().weekNumber() % 2)
        {
            ui->label_ThisWeek->setText("This week: numerator");
            ui->radioButton_Numerator->setChecked(true);
            currentWeekType = NUMERATOR;
        }
        else
        {
            ui->label_ThisWeek->setText("This week: denominator");
            ui->radioButton_Denominator->setChecked(true);
            currentWeekType = DENOMINATOR;
        }
        break;
    case DENOMINATOR:
        if(QDate::currentDate().weekNumber() % 2 == CurrentUser::getInstance()->getSettings().getStartDate().weekNumber() % 2)
        {
            ui->label_ThisWeek->setText("This week: denominator");
            ui->radioButton_Denominator->setChecked(true);
            currentWeekType = DENOMINATOR;
        }
        else
        {
            ui->label_ThisWeek->setText("This week: numerator");
            ui->radioButton_Numerator->setChecked(true);
            currentWeekType = NUMERATOR;
        }
        break;
    case NULLTYPE:
        ui->label_ThisWeek->hide();
        ui->radioButton_Numerator->hide();
        ui->radioButton_Denominator->hide();
        currentWeekType = NULLTYPE;
        break;
    }
}

void TimetableMain::setTablesSize()
{
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
}

void TimetableMain::showTimetable()
{
    timetable.clear();
    ui->tableWidget_Timetable->clear();
    QTableWidgetItem tableItem;
    for(auto& item : CurrentUser::getInstance()->getTimetable())
    {
        if(item.second.getRepeating() == currentWeekType || item.second.getRepeating() == NULLTYPE)
        {
            tableItem = QTableWidgetItem(item.second.getSubject().getName());
            tableItem.setBackground(item.second.getSubject().getColor().getColor());
            tableItem.setTextAlignment(Qt::AlignCenter);
            timetable.emplace(std::make_pair(item.first.first, item.first.second), tableItem);
        }
    }

    for(auto& item : timetable)
    {
        ui->tableWidget_Timetable->setItem(item.first.first, item.first.second, &item.second);
    }
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
    if(!ui->tableWidget_Timetable->item(row, column))
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
    if(iterator->second.getRepeating() != currentWeekType)
    {
        ++iterator;
    }
    emit OpenPlanEditing((*iterator).second);
}

void TimetableMain::editPlan(Plan plan)
{
    int lesson = ui->tableWidget_Timetable->currentRow();
    int day = ui->tableWidget_Timetable->currentColumn();
    CurrentUser::getInstance()->getTimetable().find(std::make_pair(lesson, day))->second = plan;
    showTimetable();
}

void TimetableMain::Delete()
{
    int lesson = ui->tableWidget_Timetable->currentRow();
    int day = ui->tableWidget_Timetable->currentColumn();
    CurrentUser::getInstance()->getTimetable().erase(CurrentUser::getInstance()->getTimetable().find(std::make_pair(lesson, day)));
    showTimetable();
}

void TimetableMain::addPlan(Plan plan)
{
    CurrentUser::getInstance()->getTimetable().emplace(std::make_pair(plan.getLesson(), plan.getDay()), plan);
    showTimetable();
}

void TimetableMain::on_radioButton_Numerator_clicked()
{
    currentWeekType = NUMERATOR;
    showTimetable();
}

void TimetableMain::on_radioButton_Denominator_clicked()
{
    currentWeekType = DENOMINATOR;
    showTimetable();
}

