#include "gradesmain.h"
#include "ui_gradesmain.h"
#include "currentuser.h"
#include "cache.h"

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
    Cache::writeSubjects(CurrentUser::getInstance()->getSubjects());
    Cache::writeGrades(CurrentUser::getInstance()->getGrades());
    delete ui;
}

int GradesMain::getGradeIndex()
{
    int index = ui->listWidget_Grades->currentRow();
    int extraRows = 0;
    for(int i = 0; i < index; i++)
    {
        if(ui->listWidget_Grades->item(i)->textAlignment() == Qt::AlignCenter)
        {
            extraRows++;
        }
    }
    return index - extraRows;
}

void GradesMain::showGradesList()
{
    ui->listWidget_Grades->clear();
    std::vector<Grade> grades = CurrentUser::getInstance()->getGrades();
    QString itemText = "";
    QString currentSubject = "";
    for(Grade item : grades)
    {
        if(currentSubject != item.getSubject().getName())
        {
            currentSubject = item.getSubject().getName();
            ui->listWidget_Grades->addItem(item.getSubject().getName());
            ui->listWidget_Grades->item(ui->listWidget_Grades->count() - 1)->setTextAlignment(Qt::AlignCenter);
            ui->listWidget_Grades->item(ui->listWidget_Grades->count() - 1)->setForeground(Qt::blue);
        }
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
    if(item->foreground().color() != Qt::blue)
    {
        emit OpenEditOrDelete();
    }
}

void GradesMain::OpenEditingWindow()
{
    Grade grade = CurrentUser::getInstance()->getGrades()[getGradeIndex()];
    emit OpenGradeEditing(grade);
}

void GradesMain::editGrade(Grade grade)
{
    int index = getGradeIndex();
    CurrentUser::getInstance()->getGrades()[index] = grade;
    sort(CurrentUser::getInstance()->getGrades().begin(), CurrentUser::getInstance()->getGrades().end());
    updateSubjectStatistic(grade.getSubject().getName());
    showGradesList();
}

void GradesMain::Delete()
{
    auto gradeIterator = CurrentUser::getInstance()->getGrades().begin();
    for(int i = 0; i < ui->listWidget_Grades->currentRow(); i++)
    {
        if(ui->listWidget_Grades->item(i)->textAlignment() != Qt::AlignCenter)
        {
            ++gradeIterator;
        }
    }
    QString subjectName = gradeIterator->getSubject().getName();
    CurrentUser::getInstance()->getGrades().erase(gradeIterator);
    updateSubjectStatistic(subjectName);
    showGradesList();
}

void GradesMain::addGrade(Grade grade)
{
    CurrentUser::getInstance()->getGrades().push_back(grade);
    sort(CurrentUser::getInstance()->getGrades().begin(), CurrentUser::getInstance()->getGrades().end());
    updateSubjectStatistic(grade.getSubject().getName());
    showGradesList();
}

void GradesMain::updateSubjectStatistic(QString subjectName)
{
    for(Subject& subject : CurrentUser::getInstance()->getSubjects())
    {
        if(subject.getName() == subjectName)
        {
            int gradesSum = 0;
            int gradesCount = 0;
            for(Grade grade : CurrentUser::getInstance()->getGrades())
            {
                if(grade.getSubject().getName() == subjectName)
                {
                    gradesSum += grade.getCurrentGrade();
                    gradesCount++;
                }
                if(gradesSum != 0 && grade.getSubject().getName() != subjectName)
                {
                    break;
                }
            }
            if(CurrentUser::getInstance()->getSettings().getGradingSystem() == SUM)
            {
                subject.setStatistic(gradesSum);
            }
            else if(gradesCount != 0)
            {
                if((gradesSum % gradesCount) / (double)gradesCount >= 0.5)
                {
                    subject.setStatistic(gradesSum / gradesCount + 1);
                }
                else
                {
                    subject.setStatistic(gradesSum / gradesCount);
                }
            }
            else
            {
                subject.setStatistic(0);
            }
            break;
        }
    }
}
