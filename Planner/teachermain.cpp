#include "teachermain.h"
#include "ui_teachermain.h"

TeacherMain::TeacherMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeacherMain)
{
    ui->setupUi(this);
}

TeacherMain::~TeacherMain()
{
    delete ui;
}

