#include "gradesmain.h"
#include "ui_gradesmain.h"
#include "currentuser.h"
#define MAX_GRADE_LENGTH 3
#define MAX_SUBJECT_LENGTH 98

GradesMain::GradesMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradesMain)
{
    ui->setupUi(this);
    showGradesList();
}

GradesMain::~GradesMain()
{
    delete ui;
}

void GradesMain::showGradesList()
{
    ui->listWidget_Grades->clear();
    std::vector<Grade> grades = CurrentUser::getInstance()->getGrades();
    QString itemText = "";
    for(Grade item : grades)
    {
        itemText += QString::number(item.getCurrentGrade()) + '/' + QString::number(item.getMaxGrade()) + ' ' + item.getSubject().getName() + '\n';
        if(item.getNote() != "")
        {
            itemText += " - Note: " + item.getNote() + '\n';
        }
        itemText += item.getDate().toString("dd.MM.yyyy").rightJustified(120, ' ');
        ui->listWidget_Grades->addItem(itemText);
        itemText = "";
    }
}

void GradesMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void GradesMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void GradesMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void GradesMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void GradesMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void GradesMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void GradesMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void GradesMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}

void GradesMain::on_pushButton_AddGrade_clicked()
{
    emit OpenGradeAdding();
}

void GradesMain::on_listWidget_Grades_itemClicked(QListWidgetItem *item)
{
    emit OpenEditOrDelete();
}

void GradesMain::OpenEditingWindow()
{
    Grade grade = CurrentUser::getInstance()->getGrades()[ui->listWidget_Grades->currentRow()];
    emit OpenGradeEditing(grade);
}

void GradesMain::editGrade(Grade grade)
{
    int index = ui->listWidget_Grades->currentRow();
    CurrentUser::getInstance()->getGrades()[index] = grade;
    sort(CurrentUser::getInstance()->getGrades().begin(), CurrentUser::getInstance()->getGrades().end());
    showGradesList();
}

void GradesMain::Delete()
{
    auto gradeIterator = CurrentUser::getInstance()->getGrades().begin();
    for(int i = 0; i < ui->listWidget_Grades->currentRow(); i++)
    {
        ++gradeIterator;
    }
    CurrentUser::getInstance()->getGrades().erase(gradeIterator);
    showGradesList();
}

void GradesMain::addGrade(Grade grade)
{
    CurrentUser::getInstance()->getGrades().push_back(grade);
    sort(CurrentUser::getInstance()->getGrades().begin(), CurrentUser::getInstance()->getGrades().end());
    showGradesList();
}
