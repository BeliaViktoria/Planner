#ifndef GRADESMAIN_H
#define GRADESMAIN_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class GradesMain;
}

class GradesMain : public QWidget
{
    Q_OBJECT

public:
    explicit GradesMain(QWidget *parent = nullptr);
    ~GradesMain();

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

private:
    Ui::GradesMain *ui;
};

#endif // GRADESMAIN_H
