#ifndef TIMETABLEMAIN_H
#define TIMETABLEMAIN_H

#include <QWidget>
#include <QListWidgetItem>
#include "plan.h"
#include <QTableWidgetItem>

namespace Ui {
class TimetableMain;
}

class TimetableMain : public QWidget
{
    Q_OBJECT

public:
    explicit TimetableMain(QWidget *parent = nullptr);
    ~TimetableMain();

private:
    void setTablesSize();
    void showTimetable();
    void setWeekType();
    void showTime();
    Plan getPlan(int lesson, int day);

signals:
    void OpenOverview();
    void OpenTimetable();
    void OpenCalendar();
    void OpenAgenda();
    void OpenSubjects();
    void OpenTeachers();
    void OpenGrades();
    void OpenSettings();
    void OpenPlanAdding(int, int);
    void OpenPlanEditing(Plan);
    void OpenClock();
    void OpenClock(QString);
    void OpenPlanInfo(Plan);
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
    void on_tableWidget_Timetable_cellClicked(int row, int column);
    void on_tableWidget_Time_1_cellClicked(int row, int column);
    void on_tableWidget_Time_2_cellClicked(int row, int column);
    void OpenPlanEditingWindow();
    void editPlan(Plan plan);
    void DeletePlan();
    void addPlan(Plan plan);
    void on_radioButton_Numerator_clicked();
    void on_radioButton_Denominator_clicked();
    void OpenEditingWindow();
    void setTime(QString);
    void Delete();

private:
    Ui::TimetableMain *ui;
    WeekType currentWeekType;
    std::map<std::pair<int, int>, QTableWidgetItem> timetable;
    std::map<std::pair<int, int>, QTableWidgetItem> times;
    std::pair<int,int> timeIndex;
};

#endif // TIMETABLEMAIN_H
