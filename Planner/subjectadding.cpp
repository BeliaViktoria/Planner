#include "subjectadding.h"
#include "ui_subjectadding.h"

SubjectAdding::SubjectAdding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectAdding)
{
    ui->setupUi(this);
}

SubjectAdding::~SubjectAdding()
{
    delete ui;
}
