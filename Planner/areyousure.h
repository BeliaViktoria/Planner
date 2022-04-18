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
    explicit AreYouSure(QWidget *parent = nullptr);
    ~AreYouSure();

private slots:
    void on_pushButton_Yes_clicked();
    void on_pushButton_No_clicked();

signals:
    void Yes();

private:
    Ui::AreYouSure *ui;
};

#endif // AREYOUSURE_H
