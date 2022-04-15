#ifndef EDITORDELETEDIALOG_H
#define EDITORDELETEDIALOG_H

#include <QWidget>

namespace Ui {
class EditOrDeleteDialog;
}

class EditOrDeleteDialog : public QWidget
{
    Q_OBJECT

public:
    explicit EditOrDeleteDialog(QWidget *parent = nullptr);
    ~EditOrDeleteDialog();

private:
    Ui::EditOrDeleteDialog *ui;
};

#endif // EDITORDELETEDIALOG_H
