#include "teachermain.h"
#include "ui_teachermain.h"
#include "currentuser.h"
#include "cache.h"
#include <algorithm>

TeacherMain::TeacherMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherMain)
{
    ui->setupUi(this);
    showTeacherList();
}

int TeacherMain::getTeachersIndex()
{
    int index = ui->listWidget_Teachers->currentRow();
    int extraRows = 0;
    for(int i = 0; i < index; i++)
    {
        if(ui->listWidget_Teachers->item(i)->textAlignment() == Qt::AlignCenter)
        {
            extraRows++;
        }
    }
    return index - extraRows;
}

void TeacherMain::showTeacherList()
{
    ui->listWidget_Teachers->clear();
    std::vector<Teacher> teachers = CurrentUser::getInstance()->getTeachers();
    QString itemText = "";
    QChar currentLetter = ' ';
    for(Teacher item : teachers)
    {
        if(currentLetter != item.getFullname().at(0))
        {
            currentLetter = item.getFullname().at(0);
            ui->listWidget_Teachers->addItem(item.getFullname().at(0));
            ui->listWidget_Teachers->item(ui->listWidget_Teachers->count() - 1)->setTextAlignment(Qt::AlignCenter);
            ui->listWidget_Teachers->item(ui->listWidget_Teachers->count() - 1)->setForeground(Qt::blue);
        }
        itemText += item.getFullname();
        if(item.getEmail() != "-")
        {
            itemText += "\n - " + item.getEmail();
        }
        if(item.getPhone() != "-")
        {
            itemText += "\n - " + item.getPhone();
        }
        ui->listWidget_Teachers->addItem(itemText);
        itemText = "";
    }
}

TeacherMain::~TeacherMain()
{
    Cache::writeTeachers(CurrentUser::getInstance()->getTeachers());
    delete ui;
}

void TeacherMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void TeacherMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void TeacherMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void TeacherMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void TeacherMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void TeacherMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void TeacherMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void TeacherMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}

void TeacherMain::on_pushButton_AddTeacher_clicked()
{
    emit OpenTeacherAdding();
}

void TeacherMain::on_listWidget_Teachers_itemClicked(QListWidgetItem *item)
{
    if(item->textAlignment() != Qt::AlignCenter)
    {
        emit OpenEditOrDelete();
    }
}

void TeacherMain::OpenEditingWindow()
{
    Teacher teacher = CurrentUser::getInstance()->getTeachers()[getTeachersIndex()];
    emit OpenTeacherEditing(teacher);
}

void TeacherMain::editTeacher(Teacher teacher)
{
    CurrentUser::getInstance()->getTeachers()[getTeachersIndex()] = teacher;
    sort(CurrentUser::getInstance()->getTeachers().begin(), CurrentUser::getInstance()->getTeachers().end());
    showTeacherList();
}

void TeacherMain::Delete()
{
    auto teacherIterator = CurrentUser::getInstance()->getTeachers().begin();
    for(int i = 0; i < getTeachersIndex(); i++)
    {
        ++teacherIterator;
    }
    CurrentUser::getInstance()->getTeachers().erase(teacherIterator);
    showTeacherList();
}

void TeacherMain::addTeacher(Teacher teacher)
{
    CurrentUser::getInstance()->getTeachers().push_back(teacher);
    sort(CurrentUser::getInstance()->getTeachers().begin(), CurrentUser::getInstance()->getTeachers().end());
    showTeacherList();
}

