#include "calendarmain.h"
#include "ui_calendarmain.h"

CalendarMain::CalendarMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarMain)
{
    ui->setupUi(this);
}

CalendarMain::~CalendarMain()
{
    delete ui;
}
