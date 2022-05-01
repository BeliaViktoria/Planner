#include "editdeletemarkasdomedialog.h"
#include "ui_editdeletemarkasdomedialog.h"

EditDeleteMarkAsDomeDialog::EditDeleteMarkAsDomeDialog(bool taskStatus) :
    QWidget(nullptr),
    ui(new Ui::EditDeleteMarkAsDomeDialog)
{
    ui->setupUi(this);
    if(taskStatus)
    {
        ui->pushButton_MarkAsDone->setText("Uncomplete");
    }
    else
    {
        ui->pushButton_MarkAsDone->setText("Complete");
    }
}

EditDeleteMarkAsDomeDialog::~EditDeleteMarkAsDomeDialog()
{
    delete ui;
}

void EditDeleteMarkAsDomeDialog::on_pushButton_Edit_clicked()
{
    emit Edit();
    this->close();
}

void EditDeleteMarkAsDomeDialog::on_pushButton_Delete_clicked()
{
    emit Delete();
    this->close();
}

void EditDeleteMarkAsDomeDialog::on_pushButton_MarkAsDone_clicked()
{
    emit ChangeTaskStatus();
    this->close();
}
