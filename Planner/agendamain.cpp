#include "agendamain.h"
#include "ui_agendamain.h"
#include "currentuser.h"

AgendaMain::AgendaMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgendaMain)
{
    ui->setupUi(this);
    showAgendaList();
}

AgendaMain::~AgendaMain()
{
    delete ui;
}

void AgendaMain::showAgendaList()
{
    ui->listWidget_Tasks->clear();
    std::vector<Task> agenda = CurrentUser::getInstance()->getAgenda();
    QDate currentDate = QDate();
    int currentDateIndex = -1;
    QString itemText = "";
    QString status = "Finished";
    for(Task item : agenda)
    {
        if(item.getDeadline() != currentDate)
        {
            currentDate = item.getDeadline();
            int daysToDeadline = QDate::currentDate().daysTo(currentDate);
            switch(daysToDeadline)
            {
            case 0:
                ui->listWidget_Tasks->addItem("today");
                break;
            case 1:
                ui->listWidget_Tasks->addItem("tomorrow");
                break;
            case -1:
                ui->listWidget_Tasks->addItem("yesterday");
                break;
            default:
                if(daysToDeadline > 1)
                {
                    ui->listWidget_Tasks->addItem(QString::number(daysToDeadline) + " days");
                }
                else if(daysToDeadline < -1)
                {
                    ui->listWidget_Tasks->addItem(QString::number(daysToDeadline*(-1)) + " days ago");
                }
            }
            currentDateIndex = ui->listWidget_Tasks->count() - 1;
            ui->listWidget_Tasks->item(currentDateIndex)->setTextAlignment(Qt::AlignCenter);
            ui->listWidget_Tasks->item(currentDateIndex)->setForeground(Qt::blue);
            ui->listWidget_Tasks->item(currentDateIndex)->setHidden(true);
        }
        itemText += item.getName() + "\n - Subject: " + item.getSubject().getName();
        if(item.isFinished())
        {
            itemText += '\n' + status.rightJustified(120, ' ');
        }
        ui->listWidget_Tasks->addItem(itemText);
        if(!ui->radioButton_ShowFinished->isChecked() && item.isFinished())
        {
            ui->listWidget_Tasks->item(ui->listWidget_Tasks->count() - 1)->setHidden(true);
        }
        else
        {
            ui->listWidget_Tasks->item(currentDateIndex)->setHidden(false);
        }
        itemText = "";
    }
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

int AgendaMain::getTasksIndex()
{
    int index = ui->listWidget_Tasks->currentRow();
    int extraRows = 0;
    for(int i = 0; i < index; i++)
    {
        if(ui->listWidget_Tasks->item(i)->textAlignment() == Qt::AlignCenter)
        {
            extraRows++;
        }
    }
    return index - extraRows;
}

void AgendaMain::on_listWidget_Tasks_itemClicked(QListWidgetItem *item)
{
    if(item->textAlignment() != Qt::AlignCenter)
    {
        int index = getTasksIndex();
        emit OpenEditDeleteOrMarkAsDone(CurrentUser::getInstance()->getAgenda()[index].isFinished());
    }
}

void AgendaMain::OpenEditingWindow()
{
    int index = getTasksIndex();
    Task task = CurrentUser::getInstance()->getAgenda()[index];
    emit OpenTaskEditing(task);
}

void AgendaMain::editTask(Task task)
{
    int index = getTasksIndex();
    CurrentUser::getInstance()->getAgenda()[index] = task;
    sort(CurrentUser::getInstance()->getAgenda().begin(), CurrentUser::getInstance()->getAgenda().end());
    showAgendaList();
}

void AgendaMain::Delete()
{
    auto taskIterator = CurrentUser::getInstance()->getAgenda().begin();
    for(int i = 0; i < ui->listWidget_Tasks->currentRow(); i++)
    {
        if(ui->listWidget_Tasks->item(i)->textAlignment() != Qt::AlignCenter)
        {
            ++taskIterator;
        }
    }
    CurrentUser::getInstance()->getAgenda().erase(taskIterator);
    showAgendaList();
}

void AgendaMain::addTask(Task task)
{
    CurrentUser::getInstance()->getAgenda().push_back(task);
    sort(CurrentUser::getInstance()->getAgenda().begin(), CurrentUser::getInstance()->getAgenda().end());
    showAgendaList();
}

void AgendaMain::on_radioButton_ShowFinished_clicked()
{
    showAgendaList();
}

void AgendaMain::changeTaskStatus()
{
    int index = getTasksIndex();
    if(CurrentUser::getInstance()->getAgenda()[index].isFinished())
    {
        CurrentUser::getInstance()->getAgenda()[index].setFinished(false);
    }
    else
    {
        CurrentUser::getInstance()->getAgenda()[index].setFinished(true);
    }
    showAgendaList();
}

