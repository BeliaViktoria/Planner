#include "gradesadding.h"
#include "ui_gradesadding.h"

GradesAdding::GradesAdding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradesAdding)
{
    ui->setupUi(this);
}

GradesAdding::~GradesAdding()
{
    delete ui;
}
