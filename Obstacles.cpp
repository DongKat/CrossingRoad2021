#include "CrossingRoad.h"

void GotoXY(int x, int y);

Obstacles::Obstacles(int xPos, int lane, int length, int width, int speed)
{
    this->xPos = xPos;
    this->lane = lane;
    this->length = length;
    this->width = width;
    this->speed = speed;
}

void Obstacles::updatePosition()
{
   xPos += 1;
}

void Obstacles::draw()
{
    GotoXY(xPos - 1, 3 + lane*3);
    cout << " >";
}

int Obstacles::getXPos()
{
    return xPos;
}

int Obstacles::getLane()
{
    return lane;
}

void Obstacles::setXPos(int xPos)
{
    this->xPos = xPos;
}

void Obstacles::output()
{
    cout << "xPos: " << xPos << " lane: " << lane << " length: " << length << " width: " << width << endl;   
}

int Obstacles::getSpeed()
{
    return speed;
}

int Obstacles::getLength()
{
    return length;
}

int Obstacles::getWidth()
{
    return width;
}
