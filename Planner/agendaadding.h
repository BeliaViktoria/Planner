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

signals:
    void OpenPickUpDate();

private slots:
    void on_pushButton_Deadline_clicked();

private:
    Ui::AgendaAdding *ui;
};

#endif // AGENDAADDING_H
