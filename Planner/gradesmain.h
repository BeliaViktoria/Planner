#ifndef GRADESMAIN_H
#define GRADESMAIN_H

#include <QWidget>
#include <QListWidgetItem>
#include "grade.h"

namespace Ui {
class GradesMain;
}

class GradesMain : public QWidget
{
    Q_OBJECT

public:
    explicit GradesMain(QWidget *parent = nullptr);
    ~GradesMain();

private:
    void showGradesList();
    int getGradeIndex();
    void updateSubjectStatistic(QString subjectName);

signals:
    void OpenOverview();
    void OpenTimetable();
    void OpenCalendar();
    void OpenAgenda();
    void OpenSubjects();
    void OpenTeachers();
    void OpenGrades();
    void OpenSettings();
    void OpenGradeAdding();
    void OpenEditOrDelete();
    void OpenGradeEditing(Grade);

private slots:
    void on_pushButton_Timetable_clicked();
    void on_pushButton_Calendar_clicked();
    void on_pushButton_Agenda_clicked();
    void on_pushButton_Subjects_clicked();
    void on_pushButton_Teachers_clicked();
    void on_pushButton_Grades_clicked();
    void on_pushButton_Settings_clicked();
    void on_pushButton_Overview_clicked();
    void on_pushButton_AddGrade_clicked();
    void on_listWidget_Grades_itemClicked(QListWidgetItem *item);
    void OpenEditingWindow();
    void editGrade(Grade grade);
    void Delete();
    void addGrade(Grade grade);

private:
    Ui::GradesMain *ui;
};

#endif // GRADESMAIN_H
