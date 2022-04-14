#ifndef TIMETABLEITEMSADDING_H
#define TIMETABLEITEMSADDING_H

#include <QWidget>

namespace Ui {
class TimetableItemsAdding;
}

class TimetableItemsAdding : public QWidget
{
    Q_OBJECT

public:
    explicit TimetableItemsAdding(QWidget *parent = nullptr);
    ~TimetableItemsAdding();

private:
    Ui::TimetableItemsAdding *ui;
};

#endif // TIMETABLEITEMSADDING_H
