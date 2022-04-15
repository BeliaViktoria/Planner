#include "editdeletemarkasdomedialog.h"
#include "ui_editdeletemarkasdomedialog.h"

EditDeleteMarkAsDomeDialog::EditDeleteMarkAsDomeDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditDeleteMarkAsDomeDialog)
{
    ui->setupUi(this);
}

EditDeleteMarkAsDomeDialog::~EditDeleteMarkAsDomeDialog()
{
    delete ui;
}
