#ifndef SUBJECTSMAIN_H
#define SUBJECTSMAIN_H

#include <QWidget>

namespace Ui {
class SubjectsMain;
}

class SubjectsMain : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectsMain(QWidget *parent = nullptr);
    ~SubjectsMain();

private:
    Ui::SubjectsMain *ui;
};

#endif // SUBJECTSMAIN_H
