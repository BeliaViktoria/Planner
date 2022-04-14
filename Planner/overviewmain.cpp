#include "overviewmain.h"
#include "ui_overviewmain.h"

OverviewMain::OverviewMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverviewMain)
{
    ui->setupUi(this);
}

OverviewMain::~OverviewMain()
{
    delete ui;
}
