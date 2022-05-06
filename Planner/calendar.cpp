#include "calendar.h"
#include "ui_calendar.h"

Calendar::Calendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    ui->label_YourChoice->setAlignment(Qt::AlignCenter);
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    ui->label_YourChoice->setText(date.toString("dd.MM.yyyy"));
}


void Calendar::on_pushButton_Add_clicked()
{
    if(ui->label_YourChoice->text() != "")
    {
        emit SetDate(ui->label_YourChoice->text());
    }
    this->close();
}

