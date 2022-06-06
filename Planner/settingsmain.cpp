#include "settingsmain.h"
#include "ui_settingsmain.h"
#include "currentuser.h"
#include "cache.h"

SettingsMain::SettingsMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsMain)
{
    ui->setupUi(this);
    setColorTheme();
    setValidation();
    setCurrentSettings();
}

SettingsMain::~SettingsMain()
{
    Cache::writeSettings(CurrentUser::getInstance()->getSettings());
    delete ui;
}

void SettingsMain::setColorTheme()
{
    switch(CurrentUser::getInstance()->getSettings().getColorTheme())
    {
    case BLUE:
        ui->radioButton_Blue->setChecked(true);
        break;
    case RED:
        ui->radioButton_Red->setChecked(true);
        break;
    case GREEN:
        ui->radioButton_Green->setChecked(true);
        break;
    }
}

void SettingsMain::setCurrentSettings()
{
    switch(CurrentUser::getInstance()->getSettings().getGradingSystem())
    {
    case AVERAGE:
        ui->radioButton_Average->setChecked(true);
        break;
    case SUM:
        ui->radioButton_Sum->setChecked(true);
        break;
    }

    ui->lineEdit_MaxGrade->setText(QString::number(CurrentUser::getInstance()->getSettings().getMaxGrade()));
    ui->dateEdit_StartDate->setDate(CurrentUser::getInstance()->getSettings().getStartDate());
    ui->dateEdit_EndDate->setDate(CurrentUser::getInstance()->getSettings().getEndDate());

    switch(CurrentUser::getInstance()->getSettings().getStartFrom())
    {
    case NUMERATOR:
        ui->radioButton_Numerator->setChecked(true);
        break;
    case DENOMINATOR:
        ui->radioButton_Denominator->setChecked(true);
        break;
    case NULLTYPE:
        ui->radioButton_FullWeeks->setChecked(true);
        break;
    }
}

bool SettingsMain::checkFields()
{
    hideErrorLabels();
    bool status = true;
    if(ui->lineEdit_MaxGrade->text() == "")
    {
        ui->label_NessesaryField_1->show();
        status = false;
    }
    else
    {
        CurrentUser::getInstance()->getSettings().setMaxGrade(maxGrade);
    }
    if(ui->dateEdit_EndDate->date() <= ui->dateEdit_StartDate->date())
    {
        ui->label_NessesaryField_2->show();
        ui->label_SmallEndDate_1->show();
        ui->label_SmallEndDate_2->show();
        status = false;
    }
    else
    {
        CurrentUser::getInstance()->getSettings().setStartDate(startDate);
        CurrentUser::getInstance()->getSettings().setEndDate(endDate);
    }
    return status;
}

void SettingsMain::hideErrorLabels()
{
    ui->label_NessesaryField_1->hide();
    ui->label_NessesaryField_2->hide();
    ui->label_SmallEndDate_1->hide();
    ui->label_SmallEndDate_2->hide();
}

void SettingsMain::setValidation()
{
    validatorGrade.setRegularExpression(QRegularExpression("[0-9]+"));
    ui->lineEdit_MaxGrade->setValidator(&validatorGrade);
}


void SettingsMain::on_pushButton_Timetable_clicked()
{
    emit OpenTimetable();
}

void SettingsMain::on_pushButton_Calendar_clicked()
{
    emit OpenCalendar();
}

void SettingsMain::on_pushButton_Agenda_clicked()
{
    emit OpenAgenda();
}

void SettingsMain::on_pushButton_Subjects_clicked()
{
    emit OpenSubjects();
}

void SettingsMain::on_pushButton_Teachers_clicked()
{
    emit OpenTeachers();
}

void SettingsMain::on_pushButton_Grades_clicked()
{
    emit OpenGrades();
}

void SettingsMain::on_pushButton_Settings_clicked()
{
    emit OpenSettings();
}

void SettingsMain::on_pushButton_Overview_clicked()
{
    emit OpenOverview();
}

void SettingsMain::on_pushButton_StartNewTerm_clicked()
{
    emit OpenWhatToSave();
}

void SettingsMain::on_radioButton_Blue_clicked()
{
    CurrentUser::getInstance()->getSettings().setColorTheme(BLUE);
}

void SettingsMain::on_radioButton_Red_clicked()
{
    CurrentUser::getInstance()->getSettings().setColorTheme(RED);
}

void SettingsMain::on_radioButton_Green_clicked()
{
    CurrentUser::getInstance()->getSettings().setColorTheme(GREEN);
}

void SettingsMain::on_radioButton_Average_clicked()
{
    CurrentUser::getInstance()->getSettings().setGradingSystem(AVERAGE);
}

void SettingsMain::on_radioButton_Sum_clicked()
{
    CurrentUser::getInstance()->getSettings().setGradingSystem(SUM);
}

void SettingsMain::on_radioButton_Numerator_clicked()
{
    CurrentUser::getInstance()->getSettings().setStartFrom(NUMERATOR);
}

void SettingsMain::on_radioButton_Denominator_clicked()
{
    CurrentUser::getInstance()->getSettings().setStartFrom(DENOMINATOR);
}

void SettingsMain::on_radioButton_FullWeeks_clicked()
{
    CurrentUser::getInstance()->getSettings().setStartFrom(NULLTYPE);
}

void SettingsMain::on_dateEdit_StartDate_userDateChanged(const QDate &date)
{
    startDate = date;
    checkFields();
}

void SettingsMain::on_dateEdit_EndDate_userDateChanged(const QDate &date)
{
    endDate = date;
    checkFields();
}

void SettingsMain::on_lineEdit_MaxGrade_textChanged(const QString &arg1)
{
    maxGrade = arg1.toInt();
    checkFields();
}

