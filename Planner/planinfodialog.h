#ifndef PLANINFODIALOG_H
#define PLANINFODIALOG_H

#include <QWidget>
#include "plan.h"

namespace Ui {
class PlanInfoDialog;
}

class PlanInfoDialog : public QWidget
{
    Q_OBJECT

public:
    explicit PlanInfoDialog(Plan plan);
    ~PlanInfoDialog();

private:
    void showData(Plan plan);

signals:
    void Edit();
    void Delete(bool);

private slots:
    void on_pushButton_Edit_clicked();
    void on_pushButton_Delete_clicked();

private:
    Ui::PlanInfoDialog *ui;
};

#endif // PLANINFODIALOG_H
