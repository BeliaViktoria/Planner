#ifndef TEACHERMAIN_H
#define TEACHERMAIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TeacherMain; }
QT_END_NAMESPACE

class TeacherMain : public QWidget
{
    Q_OBJECT

public:
    TeacherMain(QWidget *parent = nullptr);
    ~TeacherMain();

private:
    Ui::TeacherMain *ui;
};
#endif // TEACHERMAIN_H
