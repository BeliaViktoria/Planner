#ifndef AGENDAMAIN_H
#define AGENDAMAIN_H

#include <QWidget>

namespace Ui {
class AgendaMain;
}

class AgendaMain : public QWidget
{
    Q_OBJECT

public:
    explicit AgendaMain(QWidget *parent = nullptr);
    ~AgendaMain();

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
    Ui::AgendaMain *ui;
};

#endif // AGENDAMAIN_H
