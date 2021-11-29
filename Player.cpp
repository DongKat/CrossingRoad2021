#include "CrossingRoad.h"

Player::Player(int xPos, int yPos, int length, int width)
{
    this->xPos = xPos;
    this->yPos = yPos;
    this->length = length;
    this->width = width;
}

void Player::draw()
{
    GotoXY(xPos, yPos);
    cout << "0";
}

void Player::takeKBinput()
{
    if(kbhit())
    {
        char input = getch();
        if(input == 'a')
        {
            xPos -= 1;
        }
        else if(input == 'd')
        {
            xPos += 1;
        }
        else if(input == 'w')
        {
            yPos -= 1;
        }
        else if(input == 's')
        {
            yPos += 1;
        }
    }
}

void Player::setPosition(int xPos, int yPos)
{
    this->xPos = xPos;
    this->yPos = yPos;
}

int Player::getXPos()
{
    return xPos;
}

int Player::getYPos()
{
    return yPos;
}

int Player::getLength()
{
    return length;
}

int Player::getWidth()
{
    return width;
}
