#include "timetablemain.h"
#include "ui_timetablemain.h"
#include "currentuser.h"

TimetableMain::TimetableMain(QWidget *parent) :
    QWidget(parent), ui(new Ui::TimetableMain), timeIndex(std::make_pair(-1, -1))
{
    ui->setupUi(this);
    setTablesSize();
    setWeekType();
    showTimetable();
    showTime();
}

TimetableMain::~TimetableMain()
{
    timetable.clear();
    ui->tableWidget_Timetable->clear();
    times.clear();
    ui->tableWidget_Time_1->clear();
    ui->tableWidget_Time_2->clear();
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
            timetable.emplace(item.first, tableItem);
        }
    }

    for(auto& item : timetable)
    {
        ui->tableWidget_Timetable->setItem(item.first.first, item.first.second, &item.second);
    }
    QStringList headers {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    ui->tableWidget_Timetable->setHorizontalHeaderLabels(headers);
    setOverview();
}

void TimetableMain::showTime()
{
    times.clear();
    ui->tableWidget_Time_1->clear();
    ui->tableWidget_Time_2->clear();
    QTableWidgetItem tableItem;
    for(auto& item : CurrentUser::getInstance()->getTimes())
    {
        tableItem = QTableWidgetItem(item.second.toString("hh:mm"));
        tableItem.setTextAlignment(Qt::AlignCenter);
        times.emplace(item.first, tableItem);
    }

    for(auto& item : times)
    {
        if(item.first.first < ui->tableWidget_Time_1->rowCount())
        {
            ui->tableWidget_Time_1->setItem(item.first.first, item.first.second, &item.second);
        }
        else
        {
            ui->tableWidget_Time_2->setItem(item.first.first - ui->tableWidget_Time_1->rowCount(), item.first.second, &item.second);
        }
    }
    QStringList horizontalHeaders {"Start time", "End time"};
    QStringList verticalHeaders {"5", "6", "7", "8"};
    ui->tableWidget_Time_1->setHorizontalHeaderLabels(horizontalHeaders);
    ui->tableWidget_Time_2->setHorizontalHeaderLabels(horizontalHeaders);
    ui->tableWidget_Time_2->setVerticalHeaderLabels(verticalHeaders);
    setOverview();
}

void TimetableMain::setOverview()
{
    QDate currentDate = QDate::currentDate();
    QTime currentTime = QTime::currentTime();
    int currentLesson = -1, nextLesson = -1;
    int currentDay = currentDate.dayOfWeek();
    if(currentDay >= ui->tableWidget_Timetable->rowCount())
    {
        ui->label_WhatNow->setText("Nothing");
        ui->label_WhatThen->setText("Nothing");
        return;
    }
    for(auto iterator = CurrentUser::getInstance()->getTimes().begin(); iterator != CurrentUser::getInstance()->getTimes().end(); ++iterator)
    {
        if(iterator->second > currentTime)
        {
            if(iterator->first.second == 1)
            {
                currentLesson = iterator->first.first;
                nextLesson = currentLesson + 1;
            }
            else
            {
                nextLesson = iterator->first.first;
            }
            break;
        }
    }
    if(currentLesson == -1 || !ui->tableWidget_Timetable->item(currentLesson, currentDay))
    {
        ui->label_WhatNow->setText("Nothing");
    }
    else
    {
        ui->label_WhatNow->setText(ui->tableWidget_Timetable->item(currentLesson, currentDay)->text());
    }
    if(nextLesson == -1 || nextLesson >= ui->tableWidget_Timetable->rowCount() || !ui->tableWidget_Timetable->item(nextLesson, currentDay))
    {
        ui->label_WhatThen->setText("Nothing");
    }
    else
    {
        ui->label_WhatThen->setText(ui->tableWidget_Timetable->item(nextLesson, currentDay)->text());
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

Plan TimetableMain::getPlan(int lesson, int day)
{
    auto iterator = CurrentUser::getInstance()->getTimetable().find(std::make_pair(lesson, day));
    if(iterator->second.getRepeating() != currentWeekType)
    {
        ++iterator;
    }
    return iterator->second;
}

void TimetableMain::on_tableWidget_Timetable_cellClicked(int row, int column)
{
    if(!ui->tableWidget_Timetable->item(row, column))
    {
        emit OpenPlanAdding(row, column);
    }
    else
    {
        emit OpenPlanInfo(getPlan(row, column));
    }
}

void TimetableMain::on_tableWidget_Time_1_cellClicked(int row, int column)
{
    timeIndex = std::make_pair(row, column);
    if(!ui->tableWidget_Time_1->item(row, column))
    {
        emit OpenClock();
    }
    else
    {
        emit OpenEditOrDelete();
    }
}

void TimetableMain::on_tableWidget_Time_2_cellClicked(int row, int column)
{
    timeIndex = std::make_pair(row + ui->tableWidget_Time_1->rowCount(), column);
    if(!ui->tableWidget_Time_2->item(row, column))
    {
        emit OpenClock();
    }
    else
    {
        emit OpenEditOrDelete();
    }
}

void TimetableMain::OpenPlanEditingWindow()
{
    int row = ui->tableWidget_Timetable->currentRow();
    int column = ui->tableWidget_Timetable->currentColumn();
    emit OpenPlanEditing(getPlan(row, column));
}

void TimetableMain::editPlan(Plan plan)
{
    int lesson = ui->tableWidget_Timetable->currentRow();
    int day = ui->tableWidget_Timetable->currentColumn();
    CurrentUser::getInstance()->getTimetable().find(std::make_pair(lesson, day))->second = plan;
    showTimetable();
}

void TimetableMain::DeletePlan()
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

void TimetableMain::OpenEditingWindow()
{
    auto iterator = CurrentUser::getInstance()->getTimes().find(timeIndex);
    emit OpenClock(iterator->second.toString("hh:mm"));
}

void TimetableMain::setTime(QString time)
{
    auto iterator = CurrentUser::getInstance()->getTimes().find(timeIndex);
    if(iterator == CurrentUser::getInstance()->getTimes().end())
    {
        CurrentUser::getInstance()->getTimes().emplace(timeIndex, QTime::fromString(time));
    }
    else
    {
        iterator->second = QTime::fromString(time);
    }

    if(timeIndex.second == 0)
    {
        iterator = (CurrentUser::getInstance()->getTimes().find(std::make_pair(timeIndex.first, timeIndex.second + 1)));
        if(iterator == CurrentUser::getInstance()->getTimes().end())
        {
            QTime nextTime = QTime(QTime::fromString(time).hour()+1, QTime::fromString(time).minute());
            CurrentUser::getInstance()->getTimes().emplace(std::make_pair(timeIndex.first, timeIndex.second + 1), nextTime);
        }
        else if(iterator->second < QTime::fromString(time))
        {
            QTime nextTime = QTime(QTime::fromString(time).hour()+1, QTime::fromString(time).minute());
            iterator->second = nextTime;
        }
    }
    else
    {
        iterator = (CurrentUser::getInstance()->getTimes().find(std::make_pair(timeIndex.first, timeIndex.second - 1)));
        if(iterator == CurrentUser::getInstance()->getTimes().end())
        {
            QTime nextTime = QTime(QTime::fromString(time).hour()-1, QTime::fromString(time).minute());
            CurrentUser::getInstance()->getTimes().emplace(std::make_pair(timeIndex.first, timeIndex.second - 1), nextTime);
        }
        else if(iterator->second > QTime::fromString(time))
        {
            QTime nextTime = QTime(QTime::fromString(time).hour()-1, QTime::fromString(time).minute());
            iterator->second = nextTime;
        }
    }

    showTime();
}

void TimetableMain::Delete()
{
    CurrentUser::getInstance()->getTimes().erase(CurrentUser::getInstance()->getTimes().find(timeIndex));
    if(timeIndex.second == 1)
    {
        CurrentUser::getInstance()->getTimes().erase(CurrentUser::getInstance()->getTimes().find(std::make_pair(timeIndex.first, timeIndex.second - 1)));
    }
    else
    {
        CurrentUser::getInstance()->getTimes().erase(CurrentUser::getInstance()->getTimes().find(std::make_pair(timeIndex.first, timeIndex.second + 1)));
    }
    showTime();
}
