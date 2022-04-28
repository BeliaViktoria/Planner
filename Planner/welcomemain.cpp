#include "welcomemain.h"
#include "ui_welcomemain.h"
#include "currentuser.h"

WelcomeMain::WelcomeMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeMain)
{
    ui->setupUi(this);
    hideErrorLabels();
    setValidation();
    ui->radioButton_Blue->setChecked(true);
    colorTheme = BLUE;
    ui->radioButton_Average->setChecked(true);
    gradingSystem = AVERAGE;
    ui->radioButton_FullWeeks->setChecked(true);
    startFrom = NULLTYPE;
    ui->dateEdit_StartDate->setDate(QDate::currentDate());
    ui->dateEdit_EndDate->setDate(QDate::currentDate());
}

WelcomeMain::~WelcomeMain()
{
    delete ui;
}

bool WelcomeMain::checkFields()
{
    hideErrorLabels();
    bool status = true;
    if(ui->lineEdit_MaxGrade->text() == "")
    {
        ui->label_NessesaryField_1->show();
        status = false;
    }
    if(ui->dateEdit_EndDate->date() <= ui->dateEdit_StartDate->date())
    {
        ui->label_NessesaryField_2->show();
        ui->label_SmallEndDate_1->show();
        ui->label_SmallEndDate_2->show();
        status = false;
    }
    return status;
}

void WelcomeMain::hideErrorLabels()
{
    ui->label_NessesaryField_1->hide();
    ui->label_NessesaryField_2->hide();
    ui->label_SmallEndDate_1->hide();
    ui->label_SmallEndDate_2->hide();
}

void WelcomeMain::setValidation()
{
    validatorGrade.setRegularExpression(QRegularExpression("[0-9]+"));
    ui->lineEdit_MaxGrade->setValidator(&validatorGrade);
}

void WelcomeMain::on_pushButton_Save_clicked()
{
    if(checkFields())
    {
        Settings settings = Settings(colorTheme, gradingSystem, ui->lineEdit_MaxGrade->text().toInt(),
                                     ui->dateEdit_StartDate->date(), ui->dateEdit_EndDate->date(), startFrom);
        CurrentUser::getInstance()->setSettings(settings);
        emit OpenOverview();
    }
}

void WelcomeMain::on_radioButton_Blue_clicked()
{
    colorTheme = BLUE;
}

void WelcomeMain::on_radioButton_Red_clicked()
{
    colorTheme = RED;
}

void WelcomeMain::on_radioButton_Green_clicked()
{
    colorTheme = GREEN;
}

void WelcomeMain::on_radioButton_Average_clicked()
{
    gradingSystem = AVERAGE;
}

void WelcomeMain::on_radioButton_Sum_clicked()
{
    gradingSystem = SUM;
}

void WelcomeMain::on_radioButton_Numerator_clicked()
{
    startFrom = NUMERATOR;
}

void WelcomeMain::on_radioButton_Denominator_clicked()
{
    startFrom = DENOMINATOR;
}

void WelcomeMain::on_radioButton_FullWeeks_clicked()
{
    startFrom = NULLTYPE;
}

