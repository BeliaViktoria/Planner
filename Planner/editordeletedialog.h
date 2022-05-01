#ifndef EDITORDELETEDIALOG_H
#define EDITORDELETEDIALOG_H

#include <QWidget>

namespace Ui {
class EditOrDeleteDialog;
}

class EditOrDeleteDialog : public QWidget
{
    Q_OBJECT

public:
    explicit EditOrDeleteDialog(QWidget *parent = nullptr);
    ~EditOrDeleteDialog();

signals:
    void Edit();
    void Delete();

private slots:
    void on_pushButton_Edit_clicked();
    void on_pushButton_Delete_clicked();

private:
    Ui::EditOrDeleteDialog *ui;
};

#endif // EDITORDELETEDIALOG_H
