#ifndef SETTINGSMAIN_H
#define SETTINGSMAIN_H

#include <QWidget>

namespace Ui {
class SettingsMain;
}

class SettingsMain : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsMain(QWidget *parent = nullptr);
    ~SettingsMain();

signals:
    void OpenOverview();
    void OpenTimetable();
    void OpenCalendar();
    void OpenAgenda();
    void OpenSubjects();
    void OpenTeachers();
    void OpenGrades();
    void OpenSettings();
    void OpenWelcome();

private slots:
    void on_pushButton_Timetable_clicked();
    void on_pushButton_Calendar_clicked();
    void on_pushButton_Agenda_clicked();
    void on_pushButton_Subjects_clicked();
    void on_pushButton_Teachers_clicked();
    void on_pushButton_Grades_clicked();
    void on_pushButton_Settings_clicked();
    void on_pushButton_Overview_clicked();
    void on_pushButton_StartNewTerm_clicked();

private:
    Ui::SettingsMain *ui;
};

#endif // SETTINGSMAIN_H
