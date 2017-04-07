#include "paintobjectabstract.h"


PaintObjectAbstract::PaintObjectAbstract(const Point &coord): Coord(coord)
{

}

PaintObjectAbstract::PaintObjectAbstract(double x, double y)
{
    this->Coord.setCoord(x, y);
}

PaintObjectAbstract::~PaintObjectAbstract()
{

}

