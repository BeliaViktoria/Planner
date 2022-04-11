#ifndef AGENDAADDING_H
#define AGENDAADDING_H

#include <QWidget>

namespace Ui {
class AgendaAdding;
}

class AgendaAdding : public QWidget
{
    Q_OBJECT

public:
    explicit AgendaAdding(QWidget *parent = nullptr);
    ~AgendaAdding();

private:
    Ui::AgendaAdding *ui;
};

#endif // AGENDAADDING_H
