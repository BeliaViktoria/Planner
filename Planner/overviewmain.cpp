#include "overviewmain.h"
#include "ui_overviewmain.h"
#include "currentuser.h"

OverviewMain::OverviewMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverviewMain)
{
    ui->setupUi(this);
    setOverview();
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

WeekType OverviewMain::getWeekType(QDate date)
{
    WeekType currentWeekType;
    switch(CurrentUser::getInstance()->getSettings().getStartFrom())
    {
    case NUMERATOR:
        if(date.weekNumber() % 2 == CurrentUser::getInstance()->getSettings().getStartDate().weekNumber() % 2)
        {
            currentWeekType = NUMERATOR;
        }
        else
        {
            currentWeekType = DENOMINATOR;
        }
        break;
    case DENOMINATOR:
        if(date.weekNumber() % 2 == CurrentUser::getInstance()->getSettings().getStartDate().weekNumber() % 2)
        {
            currentWeekType = DENOMINATOR;
        }
        else
        {
            currentWeekType = NUMERATOR;
        }
        break;
    case NULLTYPE:
        currentWeekType = NULLTYPE;
        break;
    }
    return currentWeekType;
}

void OverviewMain::setTodayTimetable()
{
    ui->listWidget_TodayTimetable->clear();
    QDate currentDate = QDate::currentDate();
    if(currentDate < CurrentUser::getInstance()->getSettings().getStartDate() || currentDate > CurrentUser::getInstance()->getSettings().getEndDate())
    {
        return;
    }
    int currentDay = currentDate.dayOfWeek() - 1;
    QString startTime;
    QString endTime;
    QString subject;
    for(auto iterator = CurrentUser::getInstance()->getTimetable().begin(); iterator != CurrentUser::getInstance()->getTimetable().end(); ++iterator)
    {
        if(iterator->first.second == currentDay)
        {
            if(iterator->second.getRepeating() == WeekType::NULLTYPE || iterator->second.getRepeating() == getWeekType(currentDate))
            {
                subject = iterator->second.getSubject().getName();
                if(CurrentUser::getInstance()->getTimes().find(std::make_pair(iterator->first.first, 0)) == CurrentUser::getInstance()->getTimes().end())
                {
                    ui->listWidget_TodayTimetable->addItem(QString::number(iterator->first.first + 1) + ". " + subject);
                }
                else
                {
                    startTime = CurrentUser::getInstance()->getTimes()[std::make_pair(iterator->first.first, 0)].toString("hh:mm");
                    endTime = CurrentUser::getInstance()->getTimes()[std::make_pair(iterator->first.first, 1)].toString("hh:mm");
                    ui->listWidget_TodayTimetable->addItem(QString::number(iterator->first.first + 1) + ". " + startTime + " - " + endTime + " " + subject);
                }
            }
        }
    }
}

void OverviewMain::setTodayAgenda()
{
    ui->listWidget_TodayAgenda->clear();
    QDate date = QDate::currentDate();
    QString subject = "";
    QString status = "Finished";
    QString taskName;
    for(auto iterator = CurrentUser::getInstance()->getAgenda().begin(); iterator != CurrentUser::getInstance()->getAgenda().end(); ++iterator)
    {
        if(iterator->getDeadline() == date)
        {
            if(subject != iterator->getSubject().getName())
            {
                subject = iterator->getSubject().getName();
                ui->listWidget_TodayAgenda->addItem(subject);
                int currentIndex = ui->listWidget_TodayAgenda->count() - 1;
                ui->listWidget_TodayAgenda->item(currentIndex)->setForeground(Qt::blue);
                ui->listWidget_TodayAgenda->item(currentIndex)->setTextAlignment(Qt::AlignCenter);
            }
            taskName = iterator->getName();
            if(iterator->isFinished())
            {
                 ui->listWidget_TodayAgenda->addItem(taskName + "\n                              " + status);
            }
            else
            {
                 ui->listWidget_TodayAgenda->addItem(taskName);
            }
        }
    }
}

void OverviewMain::setTomorrowTimetable()
{
    ui->listWidget_TomorrowTimetable->clear();
    QDate currentDate = QDate::currentDate();
    if(currentDate < CurrentUser::getInstance()->getSettings().getStartDate() || currentDate > CurrentUser::getInstance()->getSettings().getEndDate())
    {
        return;
    }
    int currentDay = currentDate.dayOfWeek();
    QString startTime;
    QString endTime;
    QString subject;
    for(auto iterator = CurrentUser::getInstance()->getTimetable().begin(); iterator != CurrentUser::getInstance()->getTimetable().end(); ++iterator)
    {
        if(iterator->first.second == currentDay)
        {
            if(iterator->second.getRepeating() == WeekType::NULLTYPE || iterator->second.getRepeating() == getWeekType(currentDate))
            {
                subject = iterator->second.getSubject().getName();
                if(CurrentUser::getInstance()->getTimes().find(std::make_pair(iterator->first.first, 0)) == CurrentUser::getInstance()->getTimes().end())
                {
                    ui->listWidget_TomorrowTimetable->addItem(QString::number(iterator->first.first + 1) + ". " + subject);
                }
                else
                {
                    startTime = CurrentUser::getInstance()->getTimes()[std::make_pair(iterator->first.first, 0)].toString("hh:mm");
                    endTime = CurrentUser::getInstance()->getTimes()[std::make_pair(iterator->first.first, 1)].toString("hh:mm");
                    ui->listWidget_TomorrowTimetable->addItem(QString::number(iterator->first.first + 1) + ". " + startTime + " - " + endTime + " " + subject);
                }
            }
        }
    }
}

void OverviewMain::setTomorrowAgenda()
{
    ui->listWidget_TomorrowAgenda->clear();
    QDate date = QDate::currentDate().addDays(1);
    QString subject = "";
    QString status = "Finished";
    QString taskName;
    for(auto iterator = CurrentUser::getInstance()->getAgenda().begin(); iterator != CurrentUser::getInstance()->getAgenda().end(); ++iterator)
    {
        if(iterator->getDeadline() == date)
        {
            if(subject != iterator->getSubject().getName())
            {
                subject = iterator->getSubject().getName();
                ui->listWidget_TomorrowAgenda->addItem(subject);
                int currentIndex = ui->listWidget_TomorrowAgenda->count() - 1;
                ui->listWidget_TomorrowAgenda->item(currentIndex)->setForeground(Qt::blue);
                ui->listWidget_TomorrowAgenda->item(currentIndex)->setTextAlignment(Qt::AlignCenter);
            }
            taskName = iterator->getName();
            if(iterator->isFinished())
            {
                 ui->listWidget_TomorrowAgenda->addItem(taskName + "\n                              " + status);
            }
            else
            {
                 ui->listWidget_TomorrowAgenda->addItem(taskName);
            }
        }
    }
}

void OverviewMain::setAfterTomorrowTimetable()
{
    ui->listWidget_AfterTomorrowTimetable->clear();
    QDate currentDate = QDate::currentDate();
    if(currentDate < CurrentUser::getInstance()->getSettings().getStartDate() || currentDate > CurrentUser::getInstance()->getSettings().getEndDate())
    {
        return;
    }
    int currentDay = currentDate.dayOfWeek() + 1;
    QString startTime;
    QString endTime;
    QString subject;
    for(auto iterator = CurrentUser::getInstance()->getTimetable().begin(); iterator != CurrentUser::getInstance()->getTimetable().end(); ++iterator)
    {
        if(iterator->first.second == currentDay && iterator->second.getRepeating() == getWeekType(currentDate))
        {
            if(iterator->second.getRepeating() == WeekType::NULLTYPE || iterator->second.getRepeating() == getWeekType(currentDate))
            {
                subject = iterator->second.getSubject().getName();
                if(CurrentUser::getInstance()->getTimes().find(std::make_pair(iterator->first.first, 0)) == CurrentUser::getInstance()->getTimes().end())
                {
                    ui->listWidget_AfterTomorrowTimetable->addItem(QString::number(iterator->first.first + 1) + ". " + subject);
                }
                else
                {
                    startTime = CurrentUser::getInstance()->getTimes()[std::make_pair(iterator->first.first, 0)].toString("hh:mm");
                    endTime = CurrentUser::getInstance()->getTimes()[std::make_pair(iterator->first.first, 1)].toString("hh:mm");
                    ui->listWidget_AfterTomorrowTimetable->addItem(QString::number(iterator->first.first + 1) + ". " + startTime + " - " + endTime + " " + subject);
                }
            }
        }
    }
}

void OverviewMain::setAfterTomorrowAgenda()
{
    ui->listWidget_AfterTomorrowAgenda->clear();
    QDate date = QDate::currentDate().addDays(2);
    QString subject = "";
    QString status = "Finished";
    QString taskName;
    for(auto iterator = CurrentUser::getInstance()->getAgenda().begin(); iterator != CurrentUser::getInstance()->getAgenda().end(); ++iterator)
    {
        if(iterator->getDeadline() == date)
        {
            if(subject != iterator->getSubject().getName())
            {
                subject = iterator->getSubject().getName();
                ui->listWidget_AfterTomorrowAgenda->addItem(subject);
                int currentIndex = ui->listWidget_AfterTomorrowAgenda->count() - 1;
                ui->listWidget_AfterTomorrowAgenda->item(currentIndex)->setForeground(Qt::blue);
                ui->listWidget_AfterTomorrowAgenda->item(currentIndex)->setTextAlignment(Qt::AlignCenter);
            }
            taskName = iterator->getName();
            if(iterator->isFinished())
            {
                 ui->listWidget_AfterTomorrowAgenda->addItem(taskName + "\n                              " + status);
            }
            else
            {
                 ui->listWidget_AfterTomorrowAgenda->addItem(taskName);
            }
        }
    }
}

void OverviewMain::setOverview()
{
    setTodayTimetable();
    setTodayAgenda();
    setTomorrowTimetable();
    setTomorrowAgenda();
    setAfterTomorrowTimetable();
    setAfterTomorrowAgenda();
}
