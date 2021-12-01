#include "CrossingRoad.h"

void GotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Game::Game()
{
    xMap = 90;
    lane = 9;
    yMap = 3*lane;
    Time = 0;
    frameTime = 1;
    level = 1;

    player.setPosition(30,10);
}

Game::Game(int xMap, int lane)
{
    this->xMap = xMap;
    this->lane = lane;
    yMap = 3*lane;
    Time = 0;
    level = 1;
}

void Game::updateFrame()
{
    Time += frameTime;
    for(int i = 0; i < obsList.size(); i++)
    {
        if(Time % obsList[i].getSpeed() == 0)
        {
            obsList[i].updatePosition();
        }
        
        if(obsList[i].getXPos() >= xMap)
        {
            GotoXY(xMap - 1,obsList[i].getLane()*3);
            cout << " ";
            obsList[i].setXPos(3);
        }

    }
    player.takeKBinput(*this);
}

void Game::draw()
{
    GotoXY(101,0);
    cout << Time;

    player.draw();

    for(int i = 0; i < obsList.size(); ++i)
    {
        obsList[i].draw();
    }
}

void Game::InitDraw()
{
    GotoXY(95,0);
    cout << "Time: ";
    for(int i = 1; i <= yMap; ++i)
    {
        GotoXY(0, i + 1);
        cout << "||" << endl;
        GotoXY(xMap, i + 1);
        cout << "||" << endl;
    }
}

int Game::getTime()
{
    return Time;
}

void Game::updateLevel()
{
    for(int i = 0; i < lane; ++i)
    {
        Obstacles obs(3, i, 1, 1, (rand()%3 + 2));
        obsList.push_back(obs);
    }
}

void Game::outputObs()
{
    for (int i = 0; i < obsList.size(); ++i)
        obsList[i].output();
}

bool Game::checkCollision()
{
    for(int i = 0; i < obsList.size(); ++i)
    {
        if(player.getYPos() + player.getWidth() >= obsList[i].getLane() * 3)
        {
            if(obsList[i].getXPos() + obsList[i].getLength() >= player.getXPos() || player.getXPos() + player.getLength() >= obsList[i].getXPos())
            {
                return true;
            }
        }

        if(obsList[i].getLane() * 3 + obsList[i].getWidth() >= player.getYPos())
        {
            if(player.getXPos() + player.getLength() >= obsList[i].getXPos() || obsList[i].getXPos() + obsList[i].getLength() >= player.getXPos())
            {
                return true;
            }
        }
    }
    return false;
}
