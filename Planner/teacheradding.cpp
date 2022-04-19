#include "teacheradding.h"
#include "ui_teacheradding.h"

TeacherAdding::TeacherAdding() :
    QWidget(nullptr),
    ui(new Ui::TeacherAdding)
{
    ui->setupUi(this);
    hideErrorLabels();
}

TeacherAdding::TeacherAdding(Teacher teacher) :
    QWidget(nullptr),
    ui(new Ui::TeacherAdding)
{
    ui->setupUi(this);
    hideErrorLabels();
    ui->pushButton_Add->setText("Edit");
    ui->label_AddingTeacher->setText("Editing teacher");
    ui->lineEdit_Name->setText(teacher.getFullname().split(' ')[1]);
    ui->lineEdit_Surname->setText(teacher.getFullname().split(' ')[0]);
    ui->lineEdit_Fathername->setText(teacher.getFullname().split(' ')[2]);
    ui->lineEdit_EmailAddress->setText(teacher.getEmail());
    ui->lineEdit_Phone->setText(teacher.getPhone());
}

TeacherAdding::~TeacherAdding()
{
    delete ui;
}

void TeacherAdding::hideErrorLabels()
{
    ui->label_NessesaryField_1->hide();
    ui->label_NessesaryField_2->hide();
    ui->label_NessesaryField_3->hide();
}

bool TeacherAdding::checkFields()
{
    hideErrorLabels();
    bool status = true;
    if(ui->lineEdit_Surname->text() == "")
    {
        ui->label_NessesaryField_1->show();
        status = false;
    }
    if(ui->lineEdit_Name->text() == "")
    {
        ui->label_NessesaryField_2->show();
        status = false;
    }
    if(ui->lineEdit_Fathername->text() == "")
    {
        ui->label_NessesaryField_3->show();
        status = false;
    }
    return status;
}

void TeacherAdding::on_pushButton_Add_clicked()
{
    if(checkFields())
    {
        Teacher teacher(ui->lineEdit_Surname->text(), ui->lineEdit_Name->text(),
                        ui->lineEdit_Fathername->text(), ui->lineEdit_Phone->text(), ui->lineEdit_EmailAddress->text());
        emit Save(teacher);
        this->close();
    }
}

