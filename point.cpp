#include "point.h"

Point::Point(double x, double y):xcoord(x), ycoord(y)
{

}
// Реализация "Установить" методов
void Point::setCoord(double x, double y)
{
    this->xcoord = x;
    this->ycoord = y;
}

void Point::setCoord(const Point &coords)
{
    this->xcoord = coords.xcoord;
    this->ycoord = coords.ycoord;
}
//-------------------------------------------------

// Реализация "Получить" методов
const Point &Point::getCoord() const
{
    return *this;
}

double Point::x() const { return this->xcoord;}
double Point::y() const { return this->ycoord;}
//--------------------------------------------------

// Перегруженные операции
const Point Point::operator+(const Point &other) const
{
    return Point(this->xcoord + other.xcoord,
                 this->ycoord + other.ycoord);
}

const Point Point::operator -(const Point& other) const
{
    return Point(this->xcoord - other.xcoord,
                 this->ycoord - other.ycoord);
}

const Point Point::operator =(const Point& other) // Опасный метод
{
    // Что бы не присвоили сами себе (взято из книги Эффективное использование c++ (совет 11))
    if(this == &other) return *this;
    else
    {
        this->xcoord = other.xcoord;
        this->ycoord = other.ycoord;
        return *this;
    }
}

bool Point::operator <(const Point& other) const
{
    return (this->xcoord < other.xcoord) && (this->ycoord < other.ycoord);
}

bool Point::operator >(const Point& other) const
{
    return (this->xcoord > other.xcoord) && (this->ycoord > other.ycoord);
}

bool Point::operator ==(const Point& other) const
{
    return (this->xcoord == other.xcoord) && (this->ycoord  == other.ycoord);
}

bool Point::operator !=(const Point& other) const
{
    return (this->xcoord != other.xcoord) && (this->ycoord  != other.ycoord);
}

//----------------------------------------------------

Point::~Point()
{

}

