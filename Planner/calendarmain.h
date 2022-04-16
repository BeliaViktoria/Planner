#ifndef CALENDARMAIN_H
#define CALENDARMAIN_H

#include <QWidget>

namespace Ui {
class CalendarMain;
}

class CalendarMain : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarMain(QWidget *parent = nullptr);
    ~CalendarMain();

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
    Ui::CalendarMain *ui;
};

#endif // CALENDARMAIN_H
