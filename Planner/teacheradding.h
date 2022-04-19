#ifndef TEACHERADDING_H
#define TEACHERADDING_H

#include <QWidget>
#include "teacher.h"
#include <QRegularExpressionValidator>

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
    QRegularExpressionValidator validatorFullname;
    QRegularExpressionValidator validatorPhone;
    QRegularExpressionValidator validatorEmail;
};

#endif // TEACHERADDING_H
