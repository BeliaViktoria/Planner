#include "gradesmain.h"
#include "ui_gradesmain.h"

GradesMain::GradesMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradesMain)
{
    ui->setupUi(this);
}

GradesMain::~GradesMain()
{
    delete ui;
}
