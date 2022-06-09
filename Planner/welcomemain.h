#ifndef WELCOMEMAIN_H
#define WELCOMEMAIN_H

#include <QWidget>
#include <QRegularExpressionValidator>
#include "settings.h"

namespace Ui {
class WelcomeMain;
}

class WelcomeMain : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeMain(QWidget *parent = nullptr);
    ~WelcomeMain();

private:
    bool checkFields();
    void hideErrorLabels();
    void setValidation();

signals:
    void OpenOverview();

private slots:
    void on_pushButton_Save_clicked();
    void on_radioButton_Average_clicked();
    void on_radioButton_Sum_clicked();
    void on_radioButton_Numerator_clicked();
    void on_radioButton_Denominator_clicked();
    void on_radioButton_FullWeeks_clicked();

private:
    Ui::WelcomeMain *ui;
    QRegularExpressionValidator validatorGrade;
    GradingSystem gradingSystem;
    WeekType startFrom;
};

#endif // WELCOMEMAIN_H
