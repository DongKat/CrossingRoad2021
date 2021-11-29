#include "CrossingRoad.h"

void GotoXY(int x, int y);

Obsticles::Obsticles(int xPos, int lane, int length, int width, int speed)
{
    this->xPos = xPos;
    this->lane = lane;
    this->length = length;
    this->width = width;
    this->speed = speed;
}

void Obsticles::updatePosition()
{
   xPos += 1;
}

void Obsticles::draw()
{
    GotoXY(xPos, 3 + lane*3);
    cout << ">";
}

int Obsticles::getXPos()
{
    return xPos;
}

void Obsticles::setXPos(int xPos)
{
    this->xPos = xPos;
}

void Obsticles::output()
{
    cout << "xPos: " << xPos << " lane: " << lane << " length: " << length << " width: " << width << endl;   
}

int Obsticles::getSpeed()
{
    return speed;
}