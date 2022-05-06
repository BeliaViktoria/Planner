#include "whattosave.h"
#include "ui_whattosave.h"

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
    emit OpenWelcome();
    this->close();
}

