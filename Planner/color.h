#ifndef COLOR_H
#define COLOR_H

#include <QString>
#include <QColor>

class Color
{
    QColor color;
    QString colorName;

public:
    Color();
    Color(QColor color, QString colorName);

    QString getColorName();
    QColor getColor();

    void setColorName(QString colorName);
    void setColor(QColor color);

    bool operator==(Color anotherColor);
    void operator=(Color anotherColor);
};

#endif // COLOR_H
