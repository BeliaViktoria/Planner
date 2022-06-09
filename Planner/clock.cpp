#include "clock.h"
#include "ui_clock.h"
#include <QTime>

Clock::Clock() :
    QWidget(nullptr),
    ui(new Ui::Clock), hours(-1), minutes(0)
{
    ui->setupUi(this);
    on_radioButton_AM_clicked();
    ui->label_Time->setAlignment(Qt::AlignCenter);
    ui->pushButton_Next->hide();
}

Clock::Clock(QString time) :
    QWidget(nullptr),
    ui(new Ui::Clock)
{
    hours = QTime::fromString(time).hour();
    minutes = QTime::fromString(time).minute();
    ui->setupUi(this);
    ui->label_Time->setAlignment(Qt::AlignCenter);
    if(hours >= 12)
    {
        on_radioButton_PM_clicked();
    }
    else
    {
        on_radioButton_AM_clicked();
    }
    setTime();
}

Clock::~Clock()
{
    delete ui;
}

void Clock::setTime()
{
    ui->label_Time->clear();
    if(hours != -1)
    {
        QTime time;
        time = QTime(hours, minutes);
        ui->label_Time->setText(time.toString("hh:mm"));
    }
}

void Clock::setAMHours()
{
    ui->pushButton_0->setText("0");
    ui->pushButton_1->setText("1");
    ui->pushButton_2->setText("2");
    ui->pushButton_3->setText("3");
    ui->pushButton_4->setText("4");
    ui->pushButton_5->setText("5");
    ui->pushButton_6->setText("6");
    ui->pushButton_7->setText("7");
    ui->pushButton_8->setText("8");
    ui->pushButton_9->setText("9");
    ui->pushButton_10->setText("10");
    ui->pushButton_11->setText("11");

    ui->pushButton_Back->hide();
    ui->pushButton_Next->setText("next");
    ui->radioButton_AM->show();
    ui->radioButton_PM->show();
    isHours = true;
}

void Clock::setPMHours()
{
    ui->pushButton_0->setText("12");
    ui->pushButton_1->setText("13");
    ui->pushButton_2->setText("14");
    ui->pushButton_3->setText("15");
    ui->pushButton_4->setText("16");
    ui->pushButton_5->setText("17");
    ui->pushButton_6->setText("18");
    ui->pushButton_7->setText("19");
    ui->pushButton_8->setText("20");
    ui->pushButton_9->setText("21");
    ui->pushButton_10->setText("22");
    ui->pushButton_11->setText("23");

    ui->pushButton_Back->hide();
    ui->pushButton_Next->setText("next");
    ui->radioButton_AM->show();
    ui->radioButton_PM->show();
    isHours = true;
}

void Clock::setMinutes()
{
    ui->pushButton_0->setText("0");
    ui->pushButton_1->setText("5");
    ui->pushButton_2->setText("10");
    ui->pushButton_3->setText("15");
    ui->pushButton_4->setText("20");
    ui->pushButton_5->setText("25");
    ui->pushButton_6->setText("30");
    ui->pushButton_7->setText("35");
    ui->pushButton_8->setText("40");
    ui->pushButton_9->setText("45");
    ui->pushButton_10->setText("50");
    ui->pushButton_11->setText("55");

    ui->pushButton_Back->show();
    ui->pushButton_Next->setText("save");
    ui->radioButton_AM->hide();
    ui->radioButton_PM->hide();
    isHours = false;
}

void Clock::on_pushButton_0_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_0->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_0->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_1_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_1->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_1->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_2_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_2->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_2->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_3_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_3->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_3->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_4_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_4->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_4->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_5_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_5->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_5->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_6_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_6->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_6->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_7_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_7->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_7->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_8_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_8->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_8->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_9_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_9->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_9->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_10_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_10->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_10->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_pushButton_11_clicked()
{
    if(isHours)
    {
        hours = ui->pushButton_11->text().toInt();
    }
    else
    {
        minutes = ui->pushButton_11->text().toInt();
    }
    ui->pushButton_Next->show();
    setTime();
}

void Clock::on_radioButton_AM_clicked()
{
    setAMHours();
    ui->radioButton_AM->setChecked(true);
}

void Clock::on_radioButton_PM_clicked()
{
    setPMHours();
    ui->radioButton_PM->setChecked(true);
}

void Clock::on_pushButton_Back_clicked()
{
    setAMHours();
    on_radioButton_AM_clicked();
}

void Clock::on_pushButton_Next_clicked()
{
    if(ui->pushButton_Next->text() == "next")
    {
        setMinutes();
    }
    else
    {
        QTime time = QTime(hours, minutes);
        emit Save(time.toString("hh:mm"));
        this->close();
    }
}

