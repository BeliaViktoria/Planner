#include "settingsmain.h"
#include "ui_settingsmain.h"

SettingsMain::SettingsMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsMain)
{
    ui->setupUi(this);
}

SettingsMain::~SettingsMain()
{
    delete ui;
}
