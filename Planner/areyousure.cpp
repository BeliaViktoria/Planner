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

void AreYouSure::on_pushButton_Yes_clicked()
{
    emit Yes();
    this->close();
}


void AreYouSure::on_pushButton_No_clicked()
{
    this->close();
}

