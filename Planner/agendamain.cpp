#include "agendamain.h"
#include "ui_agendamain.h"

AgendaMain::AgendaMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgendaMain)
{
    ui->setupUi(this);
}

AgendaMain::~AgendaMain()
{
    delete ui;
}
