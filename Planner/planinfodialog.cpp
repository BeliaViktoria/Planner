#include "planinfodialog.h"
#include "ui_planinfodialog.h"

PlanInfoDialog::PlanInfoDialog(Plan plan) :
    QWidget(nullptr),
    ui(new Ui::PlanInfoDialog)
{
    ui->setupUi(this);
    showData(plan);
}

PlanInfoDialog::~PlanInfoDialog()
{
    delete ui;
}

void PlanInfoDialog::showData(Plan plan)
{
    ui->label_SubjectName->setText(plan.getSubject().getName());
    if(plan.getRoom() != "-")
    {
        ui->label_RoonNumber->setText(plan.getRoom());
    }
    if(plan.getTeacher().getFullname() != "- - -")
    {
        ui->label_TeacherName->setText(plan.getTeacher().getFullname());
    }
    if(plan.getLlink() != "-")
    {
        ui->label_LinkName->setText(plan.getLlink());
    }
    switch(plan.getRepeating())
    {
    case NULLTYPE:
        ui->label_Repeating->setText("Every week");
        break;
    case NUMERATOR:
        ui->label_Repeating->setText("By numerator");
        break;
    case DENOMINATOR:
        ui->label_Repeating->setText("By denominator");
        break;
    }
}

void PlanInfoDialog::on_pushButton_Edit_clicked()
{
    emit Edit();
}

void PlanInfoDialog::on_pushButton_Delete_clicked()
{
    emit Delete(true);
}

