#ifndef AGENDAMAIN_H
#define AGENDAMAIN_H

#include <QWidget>
#include <QListWidgetItem>
#include "task.h"

namespace Ui {
class AgendaMain;
}

class AgendaMain : public QWidget
{
    Q_OBJECT

public:
    explicit AgendaMain(QWidget *parent = nullptr);
    ~AgendaMain();

private:
    void showAgendaList();
    int getTasksIndex();

signals:
    void OpenOverview();
    void OpenTimetable();
    void OpenCalendar();
    void OpenAgenda();
    void OpenSubjects();
    void OpenTeachers();
    void OpenGrades();
    void OpenSettings();
    void OpenAgendaAdding();
    void OpenEditDeleteOrMarkAsDone(bool);
    void OpenTaskEditing(Task);

private slots:
    void on_pushButton_Timetable_clicked();
    void on_pushButton_Calendar_clicked();
    void on_pushButton_Agenda_clicked();
    void on_pushButton_Subjects_clicked();
    void on_pushButton_Teachers_clicked();
    void on_pushButton_Grades_clicked();
    void on_pushButton_Settings_clicked();
    void on_pushButton_Overview_clicked();
    void on_pushButton_AddTask_clicked();
    void on_listWidget_Tasks_itemClicked(QListWidgetItem *item);
    void OpenEditingWindow();
    void editTask(Task task);
    void Delete();
    void addTask(Task task);
    void changeTaskStatus();
    void on_radioButton_ShowFinished_clicked();

private:
    Ui::AgendaMain *ui;
};

#endif // AGENDAMAIN_H
