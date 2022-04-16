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

private:
    Ui::AreYouSure *ui;
};

#endif // AREYOUSURE_H
