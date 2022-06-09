#include "areyousure.h"
#include "ui_areyousure.h"

AreYouSure::AreYouSure(bool isForPlan) :
    QWidget(nullptr),
    ui(new Ui::AreYouSure)
{
    ui->setupUi(this);
    this->isForPlan = isForPlan;
}

AreYouSure::~AreYouSure()
{
    delete ui;
}

void AreYouSure::on_pushButton_Yes_clicked()
{
    emit CloseMinorWindow();
    if(isForPlan)
    {
        emit YesForPlan();
    }
    else
    {
        emit Yes();
    }
    this->close();
}


void AreYouSure::on_pushButton_No_clicked()
{
    this->close();
}

