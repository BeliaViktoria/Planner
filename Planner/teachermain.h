#ifndef TEACHERMAIN_H
#define TEACHERMAIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TeacherMain; }
QT_END_NAMESPACE

class TeacherMain : public QWidget
{
    Q_OBJECT

public:
    TeacherMain(QWidget *parent = nullptr);
    ~TeacherMain();

signals:
    void OpenOverview();
    void OpenTimetable();
    void OpenCalendar();
    void OpenAgenda();
    void OpenSubjects();
    void OpenTeachers();
    void OpenGrades();
    void OpenSettings();

private slots:
    void on_pushButton_Timetable_clicked();
    void on_pushButton_Calendar_clicked();
    void on_pushButton_Agenda_clicked();
    void on_pushButton_Subjects_clicked();
    void on_pushButton_Teachers_clicked();
    void on_pushButton_Grades_clicked();
    void on_pushButton_Settings_clicked();
    void on_pushButton_Overview_clicked();

private:
    Ui::TeacherMain *ui;
};
#endif // TEACHERMAIN_H
