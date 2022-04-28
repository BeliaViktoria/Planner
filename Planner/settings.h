#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDate>

enum ColorTheme
{
    BLUE,
    GREEN,
    RED
};

enum GradingSystem
{
    AVERAGE,
    SUM
};

enum WeekType
{
    NUMERATOR,
    DENOMINATOR,
    NULLTYPE
};

class Settings
{
public:
    Settings();
    Settings(ColorTheme colorTheme, GradingSystem gradingSystem, int maxGrade, QDate startDate, QDate endDate, WeekType startFrom);

    ColorTheme getColorTheme();
    GradingSystem getGradingSystem();
    int getMaxGrade();
    QDate getStartDate();
    QDate getEndDate();
    WeekType getStartFrom();

    void setColorTheme(ColorTheme colorTheme);
    void setGradingSystem(GradingSystem gradingSystem);
    void setMaxGrade(int maxGrade);
    void setStartDate(QDate startDate);
    void setEndDate(QDate endDate);
    void setStartFrom(WeekType startFrom);

private:
    ColorTheme colorTheme;
    GradingSystem gradingSystem;
    int maxGrade;
    QDate startDate;
    QDate endDate;
    WeekType startFrom;
};

#endif // SETTINGS_H
