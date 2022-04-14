#ifndef AGENDAMAIN_H
#define AGENDAMAIN_H

#include <QWidget>

namespace Ui {
class AgendaMain;
}

class AgendaMain : public QWidget
{
    Q_OBJECT

public:
    explicit AgendaMain(QWidget *parent = nullptr);
    ~AgendaMain();

private:
    Ui::AgendaMain *ui;
};

#endif // AGENDAMAIN_H
