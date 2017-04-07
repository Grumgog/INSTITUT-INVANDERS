#include "player.h"

Player::Player(Color RGB, Point coord, short lifes):
    NPC(RGB, coord),
    lifes(lifes)
{

}

void Player::addLife(short lifes)
{
    this->lifes+=lifes;
}

void Player::minLife(short lifes)
{
    if(lifes<0)lifes*=-1;

    this->lifes-=lifes;
}

short Player::getLife()
{
    return this->lifes;
}

Player::~Player()
{

}

