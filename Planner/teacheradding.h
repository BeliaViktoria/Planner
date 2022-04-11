#ifndef TEACHERADDING_H
#define TEACHERADDING_H

#include <QWidget>

namespace Ui {
class TeacherAdding;
}

class TeacherAdding : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherAdding(QWidget *parent = nullptr);
    ~TeacherAdding();

private:
    Ui::TeacherAdding *ui;
};

#endif // TEACHERADDING_H
