#include "teacheradding.h"
#include "ui_teacheradding.h"
#include "currentuser.h"
#include <QRegularExpression>


TeacherAdding::TeacherAdding() :
    QWidget(nullptr),
    ui(new Ui::TeacherAdding)
{
    ui->setupUi(this);
    hideErrorLabels();
    setValidation();
}

TeacherAdding::TeacherAdding(Teacher teacher) :
    QWidget(nullptr),
    ui(new Ui::TeacherAdding)
{
    ui->setupUi(this);
    setValidation();
    hideErrorLabels();
    ui->pushButton_Add->setText("Edit");
    ui->label_AddingTeacher->setText("Editing teacher");
    ui->lineEdit_Name->setText(teacher.getFullname().split(' ')[1]);
    ui->lineEdit_Surname->setText(teacher.getFullname().split(' ')[0]);
    ui->lineEdit_Fathername->setText(teacher.getFullname().split(' ')[2]);
    if(teacher.getEmail() != "-")
    {
        ui->lineEdit_EmailAddress->setText(teacher.getEmail());
    }
    if(teacher.getPhone() != "-")
    {
        ui->lineEdit_Phone->setText(teacher.getPhone());
    }
}

TeacherAdding::~TeacherAdding()
{
    delete ui;
}

void TeacherAdding::setValidation()
{
    validatorFullname.setRegularExpression(QRegularExpression("[a-zA-Z]+"));
    validatorEmail.setRegularExpression(QRegularExpression("[a-zA-Z0-9._%-+!#$&/=?^|~]+@[A-Za-z0-9.-]+.[A-Za-z]+"));
    validatorPhone.setRegularExpression(QRegularExpression("[+][0-9]+"));
    ui->lineEdit_Surname->setValidator(&validatorFullname);
    ui->lineEdit_Name->setValidator(&validatorFullname);
    ui->lineEdit_Fathername->setValidator(&validatorFullname);
    ui->lineEdit_Phone->setValidator(&validatorPhone);
    ui->lineEdit_EmailAddress->setValidator(&validatorEmail);
}

void TeacherAdding::hideErrorLabels()
{
    ui->label_NessesaryField_1->hide();
    ui->label_NessesaryField_2->hide();
    ui->label_NessesaryField_3->hide();
    ui->label_AlreadyExist->hide();
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
                        ui->lineEdit_Fathername->text(), "-", "-");
        if(ui->lineEdit_Phone->text() != "")
        {
            teacher.setPhone(ui->lineEdit_Phone->text());
        }
        if(ui->lineEdit_EmailAddress->text() != "")
        {
            teacher.setEmail(ui->lineEdit_EmailAddress->text());
        }
        if(ui->label_AddingTeacher->text() == "Adding teacher")
        {
            for(Teacher &item:CurrentUser::getInstance()->getTeachers())
            {
                if (teacher == item)
                {
                    ui->label_AlreadyExist->show();
                    return;
                }
            }
        }
        emit Save(teacher);
        this->close();
    }
}

