#include "whattosave.h"
#include "ui_whattosave.h"

WhatToSave::WhatToSave(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WhatToSave)
{
    ui->setupUi(this);
}

WhatToSave::~WhatToSave()
{
    delete ui;
}
