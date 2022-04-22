#ifndef EDITDELETEMARKASDOMEDIALOG_H
#define EDITDELETEMARKASDOMEDIALOG_H

#include <QWidget>

namespace Ui {
class EditDeleteMarkAsDomeDialog;
}

class EditDeleteMarkAsDomeDialog : public QWidget
{
    Q_OBJECT

public:
    explicit EditDeleteMarkAsDomeDialog(bool taskStatus);
    ~EditDeleteMarkAsDomeDialog();

signals:
    void Edit();
    void Delete();
    void ChangeTaskStatus();

private slots:
    void on_pushButton_Edit_clicked();
    void on_pushButton_Delete_clicked();
    void on_pushButton_MarkAsDone_clicked();

private:
    Ui::EditDeleteMarkAsDomeDialog *ui;
};

#endif // EDITDELETEMARKASDOMEDIALOG_H
