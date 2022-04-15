#ifndef EDITDELETEMARKASDOMEDIALOG_H
#define EDITDELETEMARKASDOMEDIALOG_H

#include <QWidget>

namespace Ui {
class EditDeleteMarkAsDomeDialog;
}

class EditDeleteMarkAsDomeDialog : public QWidget
{
    Q_OBJECT

public:
    explicit EditDeleteMarkAsDomeDialog(QWidget *parent = nullptr);
    ~EditDeleteMarkAsDomeDialog();

private:
    Ui::EditDeleteMarkAsDomeDialog *ui;
};

#endif // EDITDELETEMARKASDOMEDIALOG_H
