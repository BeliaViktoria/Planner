#include "subjectsmain.h"
#include "ui_subjectsmain.h"

SubjectsMain::SubjectsMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectsMain)
{
    ui->setupUi(this);
}

SubjectsMain::~SubjectsMain()
{
    delete ui;
}
