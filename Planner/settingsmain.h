#ifndef SETTINGSMAIN_H
#define SETTINGSMAIN_H

#include <QWidget>

namespace Ui {
class SettingsMain;
}

class SettingsMain : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsMain(QWidget *parent = nullptr);
    ~SettingsMain();

private:
    Ui::SettingsMain *ui;
};

#endif // SETTINGSMAIN_H
