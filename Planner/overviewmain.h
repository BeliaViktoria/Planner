#ifndef OVERVIEWMAIN_H
#define OVERVIEWMAIN_H

#include <QWidget>
#include "settings.h"

namespace Ui {
class OverviewMain;
}

class OverviewMain : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewMain(QWidget *parent = nullptr);
    ~OverviewMain();

private:
    void setTodayTimetable();
    void setTodayAgenda();
    void setTomorrowTimetable();
    void setTomorrowAgenda();
    void setAfterTomorrowTimetable();
    void setAfterTomorrowAgenda();
    void setOverview();
    WeekType getWeekType(QDate date);

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
    Ui::OverviewMain *ui;
};

#endif // OVERVIEWMAIN_H
