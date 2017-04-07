                                                                                                                                        #ifndef BULLET_H
#define BULLET_H
#pragma once
#include "UserClass/npc.h"
// Класс для представления пуль на поле
class Bullet : public NPC
{
private:
    bool direction;
public:
    bool getDirection();
    bool onField(double ymin, double ymax);
    void setDirection(bool direct); // Только два направления - вниз и вверх
    //void paint();
    Bullet(Color color, Point coord, bool direct);
    ~Bullet();
};

#endif // BULLET_H
