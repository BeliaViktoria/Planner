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

void OverviewMain::setTodayTimetable()
{
    QDate date = QDate::currentDate();
    ui->listWidget_TodayTimetable->clear();
    int currentDay = date.dayOfWeek() - 1;
    if(date < CurrentUser::getInstance()->getSettings().getStartDate() || date > CurrentUser::getInstance()->getSettings().getEndDate() || currentDay >= 6)
    {
        return;
    }
    QString startTime;
    QString endTime;
    QString subject;
    for(auto iterator = CurrentUser::getInstance()->getTimetable().begin(); iterator != CurrentUser::getInstance()->getTimetable().end(); ++iterator)
    {
        if(iterator->first.second == currentDay)
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
        if(iterator->first.second > currentDay)
        {
            break;
        }
    }
}

void OverviewMain::setTodayAgenda()
{
    QDate date = QDate::currentDate();
    ui->listWidget_TodayAgenda->clear();
    QString subject = "";
    QString status = "Finished";
    QString taskName;;
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
        if(iterator->getDeadline() > date)
        {
            break;
        }
    }
}

void OverviewMain::setTomorrowTimetable()
{
    QDate date = QDate::currentDate().addDays(1);
    ui->listWidget_TomorrowTimetable->clear();
    int currentDay = date.dayOfWeek() - 1;
    if(date < CurrentUser::getInstance()->getSettings().getStartDate() || date > CurrentUser::getInstance()->getSettings().getEndDate() || currentDay >= 6)
    {
        return;
    }
    QString startTime;
    QString endTime;
    QString subject;
    for(auto iterator = CurrentUser::getInstance()->getTimetable().begin(); iterator != CurrentUser::getInstance()->getTimetable().end(); ++iterator)
    {
        if(iterator->first.second == currentDay)
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
        if(iterator->first.second > currentDay)
        {
            break;
        }
    }
}

void OverviewMain::setTomorrowAgenda()
{
    QDate date = QDate::currentDate().addDays(1);
    ui->listWidget_TomorrowAgenda->clear();
    QString subject = "";
    QString status = "Finished";
    QString taskName;;
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
        if(iterator->getDeadline() > date)
        {
            break;
        }
    }
}

void OverviewMain::setAfterTomorrowTimetable()
{
    QDate date = QDate::currentDate().addDays(2);
    ui->listWidget_AfterTomorrowTimetable->clear();
    int currentDay = date.dayOfWeek() - 1;
    if(date < CurrentUser::getInstance()->getSettings().getStartDate() || date > CurrentUser::getInstance()->getSettings().getEndDate() || currentDay >= 6)
    {
        return;
    }
    QString startTime;
    QString endTime;
    QString subject;
    for(auto iterator = CurrentUser::getInstance()->getTimetable().begin(); iterator != CurrentUser::getInstance()->getTimetable().end(); ++iterator)
    {
        if(iterator->first.second == currentDay)
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
        if(iterator->first.second > currentDay)
        {
            break;
        }
    }
}

void OverviewMain::setAfterTomorrowAgenda()
{
    QDate date = QDate::currentDate().addDays(2);
    ui->listWidget_AfterTomorrowAgenda->clear();
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
        if(iterator->getDeadline() > date)
        {
            break;
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
