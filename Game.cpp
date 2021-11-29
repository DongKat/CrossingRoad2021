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
        
        if(obsList[i].getXPos() > xMap)
        {
            obsList[i].setXPos(3);
        }

    }
}

void Game::draw()
{
    GotoXY(0,0);
    cout << "Time: " << Time << " ms" << endl;
    for(int i = 0; i < yMap; ++i)
    {
        GotoXY(0, i + 1);
        cout << "||" << endl;
        GotoXY(xMap, i + 1);
        cout << "||" << endl;
    }

    for(int i = 0; i < obsList.size(); ++i)
    {
        obsList[i].draw();
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
        Obstacles obs(3, i, 1, 1, (rand()%4 + 1));
        obsList.push_back(obs);
    }
}

void Game::outputObs()
{
    for (int i = 0; i < obsList.size(); ++i)
        obsList[i].output();
}

