#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>

namespace Ui {
class Clock;
}

class Clock : public QWidget
{
    Q_OBJECT

public:
    explicit Clock();
    explicit Clock(QString);
    ~Clock();

private:
    void setAMHours();
    void setPMHours();
    void setMinutes();
    void releaseButtons();
    void setTime();

signals:
    void Save(QString);

private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_radioButton_AM_clicked();
    void on_radioButton_PM_clicked();
    void on_pushButton_Back_clicked();
    void on_pushButton_Next_clicked();

private:
    Ui::Clock *ui;
    int hours;
    int minutes;
    bool isHours;
};

#endif // CLOCK_H
