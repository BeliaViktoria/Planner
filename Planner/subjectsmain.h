#ifndef SUBJECTSMAIN_H
#define SUBJECTSMAIN_H

#include <QWidget>
#include <QListWidgetItem>
#include "subject.h"

namespace Ui {
class SubjectsMain;
}

class SubjectsMain : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectsMain(QWidget *parent = nullptr);
    ~SubjectsMain();

private:
    void showSubjectsList();

signals:
    void OpenOverview();
    void OpenTimetable();
    void OpenCalendar();
    void OpenAgenda();
    void OpenSubjects();
    void OpenTeachers();
    void OpenGrades();
    void OpenSettings();
    void OpenSubjectAdding();
    void OpenEditOrDelete();
    void OpenSubjectEditing(Subject);

private slots:
    void on_pushButton_Timetable_clicked();
    void on_pushButton_Calendar_clicked();
    void on_pushButton_Agenda_clicked();
    void on_pushButton_Subjects_clicked();
    void on_pushButton_Teachers_clicked();
    void on_pushButton_Grades_clicked();
    void on_pushButton_Settings_clicked();
    void on_pushButton_Overview_clicked();
    void on_pushButton_AddSubject_clicked();
    void on_listWidget_Subjects_itemClicked(QListWidgetItem *item);
    void OpenEditingWindow();
    void editSubject(Subject subject);
    void Delete();
    void addSubject(Subject subject);

private:
    Ui::SubjectsMain *ui;
};

#endif // SUBJECTSMAIN_H
