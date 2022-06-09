#include "settings.h"

Settings::Settings()
{
    gradingSystem = AVERAGE;
    isActual = false;
    startFrom = NULLTYPE;
    maxGrade = 0;
    startDate = QDate::currentDate();
    endDate = QDate::currentDate();
}

Settings::Settings(GradingSystem gradingSystem, int maxGrade, QDate startDate, QDate endDate, WeekType startFrom, bool isActual)
{
    this->gradingSystem = gradingSystem;
    this->maxGrade = maxGrade;
    this->startDate = startDate;
    this->endDate = endDate;
    this->startFrom = startFrom;
    this->isActual = isActual;
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

bool Settings::getIsActual()
{
    return isActual;
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

void Settings::setIsActual(bool isActual)
{
    this->isActual = isActual;
}

std::ostream& operator<<(std::ostream& out, const Settings& settings)
{
    out << settings.isActual << " " << settings.gradingSystem << " " << settings.maxGrade << " " << settings.startDate.toString("dd.MM.yyyy").toStdString() << " " << settings.endDate.toString("dd.MM.yyyy").toStdString() << " " << settings.startFrom;
    return out;
}

std::istream& operator>>(std::istream& in, Settings& settings)
{
    int gradingSystem, startFrom;
    std::string startDate, endDate;
    in >> settings.isActual >> gradingSystem >> settings.maxGrade >> startDate >> endDate >> startFrom;
    settings.setGradingSystem(GradingSystem(gradingSystem));
    settings.setStartFrom(WeekType(startFrom));
    settings.setStartDate(QDate::fromString(QString::fromStdString(startDate), "dd.MM.yyyy"));
    settings.setEndDate(QDate::fromString(QString::fromStdString(endDate), "dd.MM.yyyy"));
    return in;
}
