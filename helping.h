#ifndef HELPING_H
#define HELPING_H
#pragma once
// Вспомагательные функции для вычислений
#include <vector>
#include "UserClass/paintobjectabstract.h"
void getOpengGlSizeWindow(double& minx, double& maxx, double &miny, double &maxy, double w, double h, double ort);

// Функция для добавления элементов из других векторов в вектор рисования
template<typename T>
void addVector(std::vector<PaintObjectAbstract*> &first, const std::vector<T> &other)
{
    for(unsigned int i = 0; i < other.size(); i++)
        first.push_back(other.at(i));
}

#endif // HELPING_H
