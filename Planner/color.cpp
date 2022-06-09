#include "color.h"

Color::Color() : color(), colorName("")
{

}

Color::Color(QColor color, QString colorName)
{
    this->color = color;
    this->colorName = colorName;
}

QString Color::getColorName()
{
    return colorName;
}

QColor Color::getColor()
{
    return color;
}

void Color::setColorName(QString colorName)
{
    this->colorName = colorName;
}

void Color::setColor(QColor color)
{
    this->color = color;
}

bool Color::operator==(Color anotherColor)
{
    if(colorName == anotherColor.colorName && color == anotherColor.color)
    {
        return true;
    }
    return false;
}

void Color::operator=(Color anotherColor)
{
    this->color = anotherColor.color;
    this->colorName = anotherColor.colorName;
}

std::ostream& operator<<(std::ostream& out, const Color& color)
{
    out << color.colorName.toStdString() << " " << color.color.red() << " " << color.color.green() << " " << color.color.blue();
    return out;
}

std::istream& operator>>(std::istream& in, Color& color)
{
    int red, green, blue;
    std::string name;
    in >> name >> red >> green >> blue;
    color.setColorName(QString::fromStdString(name));
    color.setColor(QColor(red, green, blue));
    return in;
}
