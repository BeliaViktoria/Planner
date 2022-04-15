#ifndef WELCOMEMAIN_H
#define WELCOMEMAIN_H

#include <QWidget>

namespace Ui {
class WelcomeMain;
}

class WelcomeMain : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeMain(QWidget *parent = nullptr);
    ~WelcomeMain();

private:
    Ui::WelcomeMain *ui;
};

#endif // WELCOMEMAIN_H
