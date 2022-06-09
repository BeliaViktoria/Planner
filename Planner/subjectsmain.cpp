#include "subjectsmain.h"
#include "ui_subjectsmain.h"
#include "currentuser.h"
#include "cache.h"

SubjectsMain::SubjectsMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectsMain)
{
    ui->setupUi(this);
    showSubjectsList();
}

SubjectsMain::~SubjectsMain()
{
    Cache::writeSubjects(CurrentUser::getInstance()->getSubjects());
    delete ui;
}

void SubjectsMain::showSubjectsList()
{
    ui->listWidget_Subjects->clear();
    std::vector<Subject> subjects = CurrentUser::getInstance()->getSubjects();
    QString itemText = "";
    QChar currentLetter = ' ';
    for(Subject item : subjects)
    {
        if(currentLetter != item.getName().at(0))
        {
            currentLetter = item.getName().at(0);
            ui->listWidget_Subjects->addItem(item.getName().at(0));
            ui->listWidget_Subjects->item(ui->listWidget_Subjects->count() - 1)->setTextAlignment(Qt::AlignCenter);
            ui->listWidget_Subjects->item(ui->listWidget_Subjects->count() - 1)->setForeground(Qt::blue);
        }
        itemText += item.getName() + "\n - Teachers: " + item.getTeachers()[0].getFullname() + ";";
        if(item.getTeachers()[1].getFullname() != "- - -")
        {
            itemText += "\n                      " + item.getTeachers()[1].getFullname() + ";";
        }
        if(item.getTeachers()[2].getFullname() != "- - -")
        {
            itemText += "\n                      " + item.getTeachers()[2].getFullname() + ";";
        }
        itemText += "\n - Statistic: " + QString::number(item.getStatistic()) + '/' + QString::number(CurrentUser::getInstance()->getSettings().getMaxGrade());
        ui->listWidget_Subjects->addItem(itemText);
        itemText = "";
    }
}

int SubjectsMain::getSubjectsIndex()
{
    int index = ui->listWidget_Subjects->currentRow();
    int extraRows = 0;
    for(int i = 0; i < index; i++)
    {
        if(ui->listWidget_Subjects->item(i)->textAlignment() == Qt::AlignCenter)
        {
            extraRows++;
        }
    }
    return index - extraRows;
}

void SubjectsMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void SubjectsMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void SubjectsMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void SubjectsMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void SubjectsMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void SubjectsMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void SubjectsMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void SubjectsMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}

void SubjectsMain::on_pushButton_AddSubject_clicked()
{
    emit OpenSubjectAdding();
}

void SubjectsMain::on_listWidget_Subjects_itemClicked(QListWidgetItem *item)
{
    if(item->textAlignment() != Qt::AlignCenter)
    {
        emit OpenEditOrDelete();
    }
}

void SubjectsMain::OpenEditingWindow()
{
    Subject subject = CurrentUser::getInstance()->getSubjects()[getSubjectsIndex()];
    emit OpenSubjectEditing(subject);
}

void SubjectsMain::editSubject(Subject subject)
{
    CurrentUser::getInstance()->getSubjects()[getSubjectsIndex()] = subject;
    sort(CurrentUser::getInstance()->getSubjects().begin(), CurrentUser::getInstance()->getSubjects().end());
    showSubjectsList();
}

void SubjectsMain::Delete()
{
    auto subjectIterator = CurrentUser::getInstance()->getSubjects().begin();
    for(int i = 0; i < getSubjectsIndex(); i++)
    {
        ++subjectIterator;
    }
    CurrentUser::getInstance()->getSubjects().erase(subjectIterator);
    showSubjectsList();
}

void SubjectsMain::addSubject(Subject subject)
{
    CurrentUser::getInstance()->getSubjects().push_back(subject);
    sort(CurrentUser::getInstance()->getSubjects().begin(), CurrentUser::getInstance()->getSubjects().end());
    showSubjectsList();
}
