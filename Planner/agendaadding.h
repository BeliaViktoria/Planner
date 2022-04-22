#ifndef AGENDAADDING_H
#define AGENDAADDING_H

#include <QWidget>
#include "task.h"
#include <QListWidgetItem>
#include <QRegularExpressionValidator>

namespace Ui {
class AgendaAdding;
}

class AgendaAdding : public QWidget
{
    Q_OBJECT

public:
    explicit AgendaAdding();
    explicit AgendaAdding(Task task);
    ~AgendaAdding();

private:
    bool checkFields();
    void hideErrorLabels();
    void setValidation();
    void showSubjectsList();
    void hideSubjects();

signals:
    void OpenPickUpDate();
    void Save(Task);

private slots:
    void on_pushButton_Deadline_clicked();
    void on_pushButton_ClearSubjects_clicked();
    void on_pushButton_Add_clicked();
    void on_listWidget_Subjects_itemDoubleClicked(QListWidgetItem *item);
    void setDate(QString date);

private:
    Ui::AgendaAdding *ui;
    QRegularExpressionValidator validatorName;
};

#endif // AGENDAADDING_H
