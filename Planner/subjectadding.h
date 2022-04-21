#ifndef SUBJECTADDING_H
#define SUBJECTADDING_H

#include <QWidget>
#include <QRegularExpressionValidator>
#include <QListWidgetItem>
#include "subject.h"

namespace Ui {
class SubjectAdding;
}

class SubjectAdding : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectAdding();
    explicit SubjectAdding(Subject subject);
    ~SubjectAdding();

private:
    bool checkFields();
    void hideErrorLabels();
    void setValidation();
    void setColor();
    void showTeachersList();

private slots:
    void on_pushButton_Add_clicked();
    void on_pushButton_ClearTeachers_clicked();
    void on_pushButton_Red_clicked();
    void on_pushButton_Orange_clicked();
    void on_pushButton_Yellow_clicked();
    void on_pushButton_LightGreen_clicked();
    void on_pushButton_Green_clicked();
    void on_pushButton_LightBlue_clicked();
    void on_pushButton_Blue_clicked();
    void on_pushButton_Purple_clicked();
    void on_pushButton_Pink_clicked();
    void on_pushButton_Brown_clicked();
    void on_pushButton_White_clicked();
    void on_listWidget_Teachers_itemDoubleClicked(QListWidgetItem *item);

signals:
    void Save(Subject);

private:
    Ui::SubjectAdding *ui;
    QRegularExpressionValidator validatorName;
    Color choosedColor;
};

#endif // SUBJECTADDING_H
