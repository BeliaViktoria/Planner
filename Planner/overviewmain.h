#ifndef OVERVIEWMAIN_H
#define OVERVIEWMAIN_H

#include <QWidget>

namespace Ui {
class OverviewMain;
}

class OverviewMain : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewMain(QWidget *parent = nullptr);
    ~OverviewMain();

private:
    Ui::OverviewMain *ui;
};

#endif // OVERVIEWMAIN_H
