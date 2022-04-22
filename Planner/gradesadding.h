#ifndef GRADESADDING_H
#define GRADESADDING_H

#include <QWidget>
#include "grade.h"
#include <QListWidgetItem>

namespace Ui {
class GradesAdding;
}

class GradesAdding : public QWidget
{
    Q_OBJECT

public:
    explicit GradesAdding();
    explicit GradesAdding(Grade grade);
    ~GradesAdding();

private:
    bool checkFields();
    void hideErrorLabels();
    void setValidation();
    void showSubjectsList();
    void hideSubjects();

signals:
    void OpenPickUpDate();
    void Save(Grade);

private slots:
    void on_pushButton_Date_clicked();
    void on_listWidget_Subjects_itemDoubleClicked(QListWidgetItem *item);
    void on_pushButton_Add_clicked();
    void on_pushButton_ClearSubjects_clicked();
    void setDate(QString date);

private:
    Ui::GradesAdding *ui;
    QRegularExpressionValidator validatorGrade;
};

#endif // GRADESADDING_H
