#include "CrossingRoad.h"

void GotoXY(int x, int y);

Player::Player()
{
	xPos = 0;
	yPos = 0;
	length = 7;
	width = 4;
}

Player::Player(int xPos, int yPos, int length, int width)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->length = length;
	this->width = width;
}

void Player::draw()
{

	//// Human looks like this █
	//GotoXY(xPos, yPos);     cout << char(219);

	// Or human looks like this:
	/*
	  / \ <- party hat
	 ('_')
	/|   |\
	 |___|
	 |_  |_
	*/

	GotoXY(xPos, yPos);     cout << " ('_') ";
	GotoXY(xPos, yPos + 1); cout << "/|   |\\";
	GotoXY(xPos, yPos + 2); cout << " |___| ";
	GotoXY(xPos, yPos + 3); cout << " |_  |_";
}

void Player::takeKBinput(Game game)
{
	if (kbhit())
	{
		char input = getch();
		if (input == 'a' || input == 'A' && xPos > 0)
		{
			clearPlayer();
			GotoXY(xPos, yPos);
			cout << " ";
			xPos -= 1;
		}
		else if (input == 'd' || input == 'D' && xPos < game.xMap - this->length)
		{
			clearPlayer();
			GotoXY(xPos, yPos);
			cout << " ";
			xPos += 1;
		}
		else if (input == 'w' || input == 'W' && yPos > 0)
		{
			clearPlayer();
			GotoXY(xPos, yPos);
			cout << " ";
			yPos -= 1;
		}
		else if (input == 's' || input == 'S' && yPos <= game.yMap - this->width)
		{
			clearPlayer();
			GotoXY(xPos, yPos);
			cout << " ";
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

void Player::clearPlayer()
{
	for(int i = 0; i < this->width; i++)
	{
		GotoXY(xPos, yPos + i);
		for(int j = 0; j < this->length; j++)
			cout << " ";
	}
}