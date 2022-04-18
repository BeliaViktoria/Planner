#ifndef TIMETABLEMAIN_H
#define TIMETABLEMAIN_H

#include <QWidget>
#include <set>
#include <QListWidgetItem>

namespace Ui {
class TimetableMain;
}

class TimetableMain : public QWidget
{
    Q_OBJECT

public:
    explicit TimetableMain(QWidget *parent = nullptr);
    ~TimetableMain();

signals:
    void OpenOverview();
    void OpenTimetable();
    void OpenCalendar();
    void OpenAgenda();
    void OpenSubjects();
    void OpenTeachers();
    void OpenGrades();
    void OpenSettings();
    void OpenPlanAdding();
    void OpenClock();

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

private:
    Ui::TimetableMain *ui;
    std::set<QListWidgetItem> teachers;
};

#endif // TIMETABLEMAIN_H
