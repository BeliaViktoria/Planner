#include "areyousure.h"
#include "ui_areyousure.h"

AreYouSure::AreYouSure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AreYouSure)
{
    ui->setupUi(this);
}

AreYouSure::~AreYouSure()
{
    delete ui;
}
