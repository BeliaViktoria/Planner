#ifndef SETTINGSMAIN_H
#define SETTINGSMAIN_H

#include <QWidget>
#include <QRegularExpressionValidator>
#include "settings.h"

namespace Ui {
class SettingsMain;
}

class SettingsMain : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsMain(QWidget *parent = nullptr);
    ~SettingsMain();

private:
    bool checkFields();
    void hideErrorLabels();
    void setValidation();
    void setCurrentSettings();

signals:
    void OpenOverview();
    void OpenTimetable();
    void OpenCalendar();
    void OpenAgenda();
    void OpenSubjects();
    void OpenTeachers();
    void OpenGrades();
    void OpenSettings();
    void OpenWhatToSave();

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

    void on_radioButton_Average_clicked();
    void on_radioButton_Sum_clicked();
    void on_radioButton_Numerator_clicked();
    void on_radioButton_Denominator_clicked();
    void on_radioButton_FullWeeks_clicked();
    void on_dateEdit_StartDate_userDateChanged(const QDate &date);
    void on_dateEdit_EndDate_userDateChanged(const QDate &date);
    void on_lineEdit_MaxGrade_textChanged(const QString &arg1);

private:
    Ui::SettingsMain *ui; 
    QRegularExpressionValidator validatorGrade;
    QDate startDate;
    QDate endDate;
    int maxGrade;
};

#endif // SETTINGSMAIN_H
