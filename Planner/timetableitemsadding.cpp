#include "timetableitemsadding.h"
#include "ui_timetableitemsadding.h"

TimetableItemsAdding::TimetableItemsAdding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimetableItemsAdding)
{
    ui->setupUi(this);
}

TimetableItemsAdding::~TimetableItemsAdding()
{
    delete ui;
}
