#include "agendaadding.h"
#include "ui_agendaadding.h"

AgendaAdding::AgendaAdding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgendaAdding)
{
    ui->setupUi(this);
}

AgendaAdding::~AgendaAdding()
{
    delete ui;
}