#include "whattosave.h"
#include "ui_whattosave.h"
#include "cache.h"
#include "currentuser.h"

WhatToSave::WhatToSave(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WhatToSave)
{
    ui->setupUi(this);
}

WhatToSave::~WhatToSave()
{
    delete ui;
}

void WhatToSave::on_checkBox_Subjects_stateChanged(int arg1)
{
    if(arg1 == 0)
    {
        subjects = false;
    }
    else
    {
        subjects = true;
        teachers = true;
        ui->checkBox_Teachers->setChecked(true);
    }
}

void WhatToSave::on_checkBox_Teachers_stateChanged(int arg1)
{
    if(arg1 == 0)
    {
        teachers = false;
    }
    else
    {
        teachers = true;
    }
}

void WhatToSave::on_checkBox_Timetable_stateChanged(int arg1)
{
    if(arg1 == 0)
    {
        timetable = false;
    }
    else
    {
        timetable = true;
    }
}

void WhatToSave::on_pushButton_ClearSubjects_clicked()
{
    if(!subjects)
    {
        Cache::deleteSubjects();
        CurrentUser::getInstance()->getSubjects().clear();
    }
    if(!teachers)
    {
        Cache::deleteTeachers();
        CurrentUser::getInstance()->getTeachers().clear();
    }
    if(!timetable)
    {
        Cache::deleteTimetable();
        CurrentUser::getInstance()->getTimetable().clear();
    }
    Cache::deleteAgenda();
    CurrentUser::getInstance()->getAgenda().clear();
    Cache::deleteGrades();
    CurrentUser::getInstance()->getGrades().clear();
    CurrentUser::getInstance()->getSettings().setIsActual(false);
    emit OpenWelcome();
    this->close();
}

