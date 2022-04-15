#ifndef GRADESADDING_H
#define GRADESADDING_H

#include <QWidget>

namespace Ui {
class GradesAdding;
}

class GradesAdding : public QWidget
{
    Q_OBJECT

public:
    explicit GradesAdding(QWidget *parent = nullptr);
    ~GradesAdding();

private:
    Ui::GradesAdding *ui;
};

#endif // GRADESADDING_H
