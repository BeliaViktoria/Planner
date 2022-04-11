#ifndef SUBJECTADDING_H
#define SUBJECTADDING_H

#include <QWidget>

namespace Ui {
class SubjectAdding;
}

class SubjectAdding : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectAdding(QWidget *parent = nullptr);
    ~SubjectAdding();

private:
    Ui::SubjectAdding *ui;
};

#endif // SUBJECTADDING_H
