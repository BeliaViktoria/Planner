#include "editordeletedialog.h"
#include "ui_editordeletedialog.h"

EditOrDeleteDialog::EditOrDeleteDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditOrDeleteDialog)
{
    ui->setupUi(this);
}

EditOrDeleteDialog::~EditOrDeleteDialog()
{
    delete ui;
}

void EditOrDeleteDialog::on_pushButton_Edit_clicked()
{
    emit Edit();
}


void EditOrDeleteDialog::on_pushButton_Delete_clicked()
{
    emit Delete();
    this->close();
}

