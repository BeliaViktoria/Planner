#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>

namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

private slots:
    void on_calendarWidget_clicked(const QDate &date);
    void on_pushButton_Add_clicked();

signals:
    void SetDate(QString);

private:
    Ui::Calendar *ui;
};

#endif // CALENDAR_H
