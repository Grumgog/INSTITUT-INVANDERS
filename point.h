#ifndef POINT_H
#define POINT_H

#pragma once
// Класс представляющий математическую точку


class Point
{
private:
    double xcoord, ycoord;
public:
    Point(double x = 0, double y = 0);

    // "Установить" методы
    void setCoord(double x, double y);
    void setCoord(const Point &coords);

    // "Получить" методы
    const Point& getCoord() const;
    double x() const;
    double y() const;

    // Перегрузка операций
    const Point operator+(const Point &other) const;
    const Point operator-(const Point &other) const;
    const Point operator=(const Point &other); // DANGER - METHOD!
    bool  operator>(const Point &other) const;
    bool  operator<(const Point &other) const;
    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

    ~Point();
};

#endif // POINT_H
