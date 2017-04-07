#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "UserClass/npc.h"
// Класс для представления игрока на поле

class Player : public NPC
{
private:
    Player(Color RGB, Point coord, short lifes);
    Player(const Player &r);
    void operator=(const Player& r);
    short lifes;
public:
    static Player& instance(Color col = 0, Point p = Point(), short l = 0)
    {
        static Player Singleton(col, p, l);
        return Singleton;
    }

    void addLife(short lifes = 1);
    void minLife(short lifes = 1);
    short getLife();

    ~Player();
};

#endif // PLAYER_H
