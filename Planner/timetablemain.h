#ifndef TIMETABLEMAIN_H
#define TIMETABLEMAIN_H

#include <QWidget>

namespace Ui {
class TimetableMain;
}

class TimetableMain : public QWidget
{
    Q_OBJECT

public:
    explicit TimetableMain(QWidget *parent = nullptr);
    ~TimetableMain();

private:
    Ui::TimetableMain *ui;
};

#endif // TIMETABLEMAIN_H
