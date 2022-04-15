#ifndef ADDGRADEDIALOG_H
#define ADDGRADEDIALOG_H

#include <QWidget>

namespace Ui {
class AddGradeDialog;
}

class AddGradeDialog : public QWidget
{
    Q_OBJECT

public:
    explicit AddGradeDialog(QWidget *parent = nullptr);
    ~AddGradeDialog();

private:
    Ui::AddGradeDialog *ui;
};

#endif // ADDGRADEDIALOG_H
