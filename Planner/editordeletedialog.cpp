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
