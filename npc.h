#ifndef NPC_H
#define NPC_H
// Класс представляет обобщенный тип для игрока и врагов и других объектов
#pragma once
#include "UserClass/paintobjectabstract.h"
#include <QGLWidget>

// Предполагается два вида отображения - с помощью текстуры и простой цветовой заливки
//#define TEXTURE

#ifndef TEXTURE
#define TOCLR(X) ((X)/256.0)
const int MASK_R = 0x00FF0000;
const int MASK_G = 0x0000FF00;
const int MASK_B = 0x000000FF;
const float sizeNPC = 0.2;
typedef int Color;
#else
typedef int Texture;
#endif



class NPC : public PaintObjectAbstract
{
private:
#ifndef TEXTURE
    Color color;
#else
    Texture texture;
#endif
protected:
    double sizeX;
    double sizeY;
public:
#ifndef TEXTURE
    NPC(Color RGB, Point coord);
#else
    NPC(Texture RGB, Point coord);
#endif

    void moveTo(Point coord);
    void moveTo(double x, double y);
    const Point getCoord();
    static bool intersection(NPC *first, NPC *second);
    void paint();
    ~NPC();
};

#endif // NPC_H
