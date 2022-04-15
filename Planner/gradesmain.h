#ifndef GRADESMAIN_H
#define GRADESMAIN_H

#include <QWidget>

namespace Ui {
class GradesMain;
}

class GradesMain : public QWidget
{
    Q_OBJECT

public:
    explicit GradesMain(QWidget *parent = nullptr);
    ~GradesMain();

private:
    Ui::GradesMain *ui;
};

#endif // GRADESMAIN_H
