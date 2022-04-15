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

signals:
    void OpenOverview();

private slots:
    void on_pushButton_Save_clicked();

private:
    Ui::WelcomeMain *ui;
};

#endif // WELCOMEMAIN_H
