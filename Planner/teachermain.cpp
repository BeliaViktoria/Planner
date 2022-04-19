#include "teachermain.h"
#include "ui_teachermain.h"
#include "currentuser.h"
#include <algorithm>

TeacherMain::TeacherMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherMain)
{
    ui->setupUi(this);
    showTeacherList();
}

void TeacherMain::showTeacherList()
{
    ui->listWidget_Teachers->clear();
    std::vector<Teacher> teachers = CurrentUser::getInstance()->getTeachers();
    QString itemText = "";
    for(Teacher item : teachers)
    {
        itemText += item.getFullname();
        if(item.getEmail() != "")
        {
            itemText += "\n - " + item.getEmail();
        }
        if(item.getPhone() != "")
        {
            itemText += "\n - " + item.getPhone();
        }
        ui->listWidget_Teachers->addItem(itemText);
        itemText = "";
    }
}

TeacherMain::~TeacherMain()
{
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
    emit OpenEditOrDelete();
}

void TeacherMain::OpenEditingWindow()
{
    auto date = ui->listWidget_Teachers->currentItem()->text().split("\n - ");
    auto fullname = date[0].split(' ');
    if(date.length() == 1)
    {
        Teacher teacher(fullname[0], fullname[1], fullname[2], "", "");
        emit OpenTeacherEditing(teacher);
    }
    else if(date.length() == 2)
    {
        Teacher teacher(fullname[0], fullname[1], fullname[2], "", date[1]);
        emit OpenTeacherEditing(teacher);
    }
    else
    {
        Teacher teacher(fullname[0], fullname[1], fullname[2], date[2], date[1]);
        emit OpenTeacherEditing(teacher);
    }
}

void TeacherMain::editTeacher(Teacher teacher)
{
    int index = ui->listWidget_Teachers->currentRow();
    CurrentUser::getInstance()->getTeachers()[index] = teacher;
    sort(CurrentUser::getInstance()->getTeachers().begin(), CurrentUser::getInstance()->getTeachers().end());
    showTeacherList();
}

void TeacherMain::Delete()
{
    auto teacherIterator = CurrentUser::getInstance()->getTeachers().begin();
    for(int i = 0; i < ui->listWidget_Teachers->currentRow(); i++)
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

