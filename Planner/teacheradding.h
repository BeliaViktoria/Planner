#ifndef TEACHERADDING_H
#define TEACHERADDING_H

#include <QWidget>
#include "teacher.h"

namespace Ui {
class TeacherAdding;
}

class TeacherAdding : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherAdding();
    explicit TeacherAdding(Teacher teacher);
    ~TeacherAdding();

private:
    bool checkFields();
    void hideErrorLabels();

private slots:
    void on_pushButton_Add_clicked();

signals:
    void Save(Teacher);

private:
    Ui::TeacherAdding *ui;
};

#endif // TEACHERADDING_H
