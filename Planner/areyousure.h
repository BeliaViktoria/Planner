#ifndef AREYOUSURE_H
#define AREYOUSURE_H

#include <QWidget>

namespace Ui {
class AreYouSure;
}

class AreYouSure : public QWidget
{
    Q_OBJECT

public:
    explicit AreYouSure(bool isForPlan);
    ~AreYouSure();

private slots:
    void on_pushButton_Yes_clicked();
    void on_pushButton_No_clicked();

signals:
    void Yes();
    void CloseMinorWindow();
    void YesForPlan();

private:
    Ui::AreYouSure *ui;
    bool isForPlan;
};

#endif // AREYOUSURE_H
