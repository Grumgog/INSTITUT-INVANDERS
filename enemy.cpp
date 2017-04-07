#include "enemy.h"

Enemy::Enemy(Color color, Point coord, unsigned int scores, bool isboss) : NPC(color, coord)
{
    this->scores = scores;
}

unsigned int Enemy::getScore()
{
    if(this->boss)
        return this->scores*3;
    else return this->scores;
}

void Enemy::SetScore(unsigned int scores)
{
    this->scores = scores;
}


Enemy::~Enemy()
{

}

