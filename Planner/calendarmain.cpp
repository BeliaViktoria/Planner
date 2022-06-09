#include "calendarmain.h"
#include "ui_calendarmain.h"
#include "currentuser.h"

CalendarMain::CalendarMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarMain)
{
    ui->setupUi(this);
    on_calendarWidget_clicked(QDate::currentDate());
}

CalendarMain::~CalendarMain()
{
    delete ui;
}

void CalendarMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void CalendarMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void CalendarMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void CalendarMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void CalendarMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void CalendarMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void CalendarMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void CalendarMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}

WeekType CalendarMain::getWeekType(QDate date)
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

void CalendarMain::setTimetable(QDate date)
{
    ui->listWidget_Timetable->clear();
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
            if(iterator->second.getRepeating() == WeekType::NULLTYPE || iterator->second.getRepeating() == getWeekType(date))
            {
                subject = iterator->second.getSubject().getName();
                if(CurrentUser::getInstance()->getTimes().find(std::make_pair(iterator->first.first, 0)) == CurrentUser::getInstance()->getTimes().end())
                {
                    ui->listWidget_Timetable->addItem(QString::number(iterator->first.first + 1) + ". " + subject);
                }
                else
                {
                    startTime = CurrentUser::getInstance()->getTimes()[std::make_pair(iterator->first.first, 0)].toString("hh:mm");
                    endTime = CurrentUser::getInstance()->getTimes()[std::make_pair(iterator->first.first, 1)].toString("hh:mm");
                    ui->listWidget_Timetable->addItem(QString::number(iterator->first.first + 1) + ". " + startTime + " - " + endTime + " " + subject);
                }
            }
        }
    }
}

void CalendarMain::setAgenda(QDate date)
{
    ui->listWidget_Agenda->clear();
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
                ui->listWidget_Agenda->addItem(subject);
                int currentIndex = ui->listWidget_Agenda->count() - 1;
                ui->listWidget_Agenda->item(currentIndex)->setForeground(iterator->getSubject().getColor().getColor());
                ui->listWidget_Agenda->item(currentIndex)->setTextAlignment(Qt::AlignCenter);
            }
            taskName = iterator->getName();
            if(iterator->isFinished())
            {
                 ui->listWidget_Agenda->addItem(taskName + "\n                                                  " + status);
            }
            else
            {
                 ui->listWidget_Agenda->addItem(taskName);
            }
        }
    }
}

void CalendarMain::on_calendarWidget_clicked(const QDate &date)
{
    setTimetable(date);
    setAgenda(date);
}

