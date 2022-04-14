#ifndef CALENDARMAIN_H
#define CALENDARMAIN_H

#include <QWidget>

namespace Ui {
class CalendarMain;
}

class CalendarMain : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarMain(QWidget *parent = nullptr);
    ~CalendarMain();

private:
    Ui::CalendarMain *ui;
};

#endif // CALENDARMAIN_H
