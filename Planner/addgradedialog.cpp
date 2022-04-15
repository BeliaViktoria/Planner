#include "addgradedialog.h"
#include "ui_addgradedialog.h"

AddGradeDialog::AddGradeDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddGradeDialog)
{
    ui->setupUi(this);
}

AddGradeDialog::~AddGradeDialog()
{
    delete ui;
}
