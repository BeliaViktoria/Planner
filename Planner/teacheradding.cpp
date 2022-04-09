#include "teacheradding.h"
#include "ui_teacheradding.h"

TeacherAdding::TeacherAdding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherAdding)
{
    ui->setupUi(this);
}

TeacherAdding::~TeacherAdding()
{
    delete ui;
}
