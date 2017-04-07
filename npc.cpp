#include "npc.h"
#include <QDebug>
#ifndef TEXTURE
NPC::NPC(Color RGB, Point coord): NPC::PaintObjectAbstract(coord)
{
    this->color = RGB;
    this->sizeX = sizeNPC;
    this->sizeY = sizeNPC;

}
#else
NPC::NPC(Texture texture, Point coord): NPC::PaintObjectAbstract(coord)
{
    this->texture = texture;
}
#endif

void NPC::moveTo(Point coord)
{
    this->Coord = coord;
}

void NPC::moveTo(double x, double y)
{
    this->Coord.setCoord(x, y);
}

const Point NPC::getCoord()
{
    return Point(Coord.x(), Coord.y());
}

void NPC::paint()
{
#ifndef TEXTURE
    glColor3f(TOCLR(this->color & MASK_R), TOCLR(this->color & MASK_G), TOCLR(this->color & MASK_B));
    glBegin(GL_QUADS);
       glVertex2d(-this->sizeX + this->Coord.x(),   this->sizeY + this->Coord.y());
       glVertex2d( this->sizeX + this->Coord.x(),   this->sizeY + this->Coord.y());
       glVertex2d( this->sizeX + this->Coord.x(),  -this->sizeY + this->Coord.y());
       glVertex2d(-this->sizeX + this->Coord.x(),  -this->sizeY + this->Coord.y());
    glEnd();
#else

#endif
}

bool intersection_(double xu, double yu, double xb, double yb, double point)
{
    bool answer = false;
    if(point>xu && point<yu && point<xb && point>yb)
    {
        answer = true;
    }
    return answer;
}

bool NPC::intersection(NPC *first, NPC *second)
{
    bool answer = false;
    double x1u = first->getCoord().x() + first->sizeX;
    double y1u = first->getCoord().y() + first->sizeY;
    double x1b = first->getCoord().x() - first->sizeX;;
    double y1b = first->getCoord().y() - first->sizeY;

    double x2u = second->getCoord().x() + second->sizeX;
    double y2u = second->getCoord().y() + second->sizeY;
    double x2b = second->getCoord().x() - second->sizeX;
    double y2b = second->getCoord().y() - second->sizeY;

      if(x1b > x2u || x1u < x2b || y1u < y2b || y1b > y2u) return false;
      return true;

}

NPC::~NPC()
{

}

