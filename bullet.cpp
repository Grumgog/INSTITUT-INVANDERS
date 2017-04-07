#include "bullet.h"

Bullet::Bullet(Color color, Point coord, bool direct):
    NPC(color, coord), direction(direct)
{
    this->sizeX=0.1;
    this->sizeY=0.2;

}

bool Bullet::getDirection()
{
    return this->direction;
}

bool Bullet::onField(double ymin, double ymax)
{
    if(this->getCoord().y() > ymin && this->getCoord().y() < ymax)
        return true;
    else return false;
}

void Bullet::setDirection(bool direct)
{
    this->direction = direct;
}

Bullet::~Bullet()
{

}

