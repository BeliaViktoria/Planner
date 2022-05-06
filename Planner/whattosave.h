#ifndef WHATTOSAVE_H
#define WHATTOSAVE_H

#include <QWidget>

namespace Ui {
class WhatToSave;
}

class WhatToSave : public QWidget
{
    Q_OBJECT

public:
    explicit WhatToSave(QWidget *parent = nullptr);
    ~WhatToSave();

signals:
    void OpenWelcome();

private slots:
    void on_checkBox_Subjects_stateChanged(int arg1);
    void on_checkBox_Teachers_stateChanged(int arg1);
    void on_checkBox_Timetable_stateChanged(int arg1);
    void on_pushButton_ClearSubjects_clicked();

private:
    Ui::WhatToSave *ui;
    bool subjects;
    bool teachers;
    bool timetable;
};

#endif // WHATTOSAVE_H
