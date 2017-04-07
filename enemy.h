#ifndef ENEMY_H
#define ENEMY_H
#pragma once
#include "UserClass/npc.h"
// Класс для представления врага на поле

class Enemy : public NPC
{
private:
    enum{notBoss=0, isBoss};
    unsigned int scores;
    bool boss;

public:
    Enemy(Color color, Point coord, unsigned int scores = 10, bool isboss = false);
    unsigned int getScore();
    void SetScore(unsigned int scores);
    ~Enemy();
};

#endif // ENEMY_H
