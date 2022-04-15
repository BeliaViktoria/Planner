#include "welcomemain.h"
#include "ui_welcomemain.h"

WelcomeMain::WelcomeMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeMain)
{
    ui->setupUi(this);
}

WelcomeMain::~WelcomeMain()
{
    delete ui;
}

void WelcomeMain::on_pushButton_Save_clicked()
{
    emit OpenOverview();
}

