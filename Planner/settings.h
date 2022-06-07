#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDate>

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
    Settings(GradingSystem gradingSystem, int maxGrade, QDate startDate, QDate endDate, WeekType startFrom, bool isActual);

    GradingSystem getGradingSystem();
    int getMaxGrade();
    QDate getStartDate();
    QDate getEndDate();
    WeekType getStartFrom();
    bool getIsActual();

    void setGradingSystem(GradingSystem gradingSystem);
    void setMaxGrade(int maxGrade);
    void setStartDate(QDate startDate);
    void setEndDate(QDate endDate);
    void setStartFrom(WeekType startFrom);
    void setIsActual(bool isActual);

    friend std::ostream& operator<<(std::ostream& out, const Settings& settings);
    friend std::istream& operator>>(std::istream& in, Settings& settings);

private:
    bool isActual;
    GradingSystem gradingSystem;
    int maxGrade;
    QDate startDate;
    QDate endDate;
    WeekType startFrom;
};

#endif // SETTINGS_H
