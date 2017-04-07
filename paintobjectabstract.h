#ifndef PAINTOBJECTABSTRACT_H
#define PAINTOBJECTABSTRACT_H
// Класс для реализации общего рисования

#pragma once
#include "UserClass/point.h"

class PaintObjectAbstract
{
protected:
    Point Coord;
public:
    // Конструкторы
    PaintObjectAbstract(const Point &coord);
    PaintObjectAbstract(double x, double y);

    // Главный виртуальный метод
    virtual void paint() = 0;

    // Виртуальный деструктор, что бы все производные классы использовали свой деструктор
    virtual ~PaintObjectAbstract();
};

#endif // PAINTOBJECTABSTRACT_H
