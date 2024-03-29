#ifndef TIMETABLEITEMSADDING_H
#define TIMETABLEITEMSADDING_H

#include <QWidget>
#include "plan.h"
#include <QListWidgetItem>

namespace Ui {
class TimetableItemsAdding;
}

class TimetableItemsAdding : public QWidget
{
    Q_OBJECT

public:
    explicit TimetableItemsAdding(int lesson, int day);
    explicit TimetableItemsAdding(Plan plan);
    ~TimetableItemsAdding();

private slots:
    void on_pushButton_ClearSubjects_clicked();
    void on_pushButton_ClearTeachers_clicked();
    void on_listWidget_Subjects_itemDoubleClicked(QListWidgetItem *item);
    void on_listWidget_Teachers_itemDoubleClicked(QListWidgetItem *item);
    void on_radioButton_Numerator_clicked();
    void on_radioButton_FullWeek_clicked();
    void on_radioButton_Denominator_clicked();
    void on_pushButton_Add_clicked();

private:
    bool checkFields();
    void hideErrorLabels();
    void setWindowSettings();
    void showSubjectsList();
    void hideSubjects();
    void showTeachersList();
    void hideTeachers();

signals:
    void Save(Plan plan);

private:
    Ui::TimetableItemsAdding *ui;
    int lesson;
    int day;
    Subject subject;
    Teacher teacher;
    WeekType repeating;
    QRegularExpressionValidator validatorRoom;
    QRegularExpressionValidator validatorLink;
};

#endif // TIMETABLEITEMSADDING_H
