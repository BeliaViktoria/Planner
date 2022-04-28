#include "settings.h"

Settings::Settings()
{

}

Settings::Settings(ColorTheme colorTheme, GradingSystem gradingSystem, int maxGrade, QDate startDate, QDate endDate, WeekType startFrom)
{
    this->colorTheme = colorTheme;
    this->gradingSystem = gradingSystem;
    this->maxGrade = maxGrade;
    this->startDate = startDate;
    this->endDate = endDate;
    this->startFrom = startFrom;
}

ColorTheme Settings::getColorTheme()
{
    return colorTheme;
}

GradingSystem Settings::getGradingSystem()
{
    return gradingSystem;
}

int Settings::getMaxGrade()
{
    return maxGrade;
}

QDate Settings::getStartDate()
{
    return startDate;
}

QDate Settings::getEndDate()
{
    return endDate;
}

WeekType Settings::getStartFrom()
{
    return startFrom;
}

void Settings::setColorTheme(ColorTheme colorTheme)
{
    this->colorTheme = colorTheme;
}

void Settings::setGradingSystem(GradingSystem gradingSystem)
{
    this->gradingSystem = gradingSystem;
}

void Settings::setMaxGrade(int maxGrade)
{
    this->maxGrade = maxGrade;
}

void Settings::setStartDate(QDate startDate)
{
    this->startDate = startDate;
}

void Settings::setEndDate(QDate endDate)
{
    this->endDate = endDate;
}

void Settings::setStartFrom(WeekType startFrom)
{
    this->startFrom = startFrom;
}
