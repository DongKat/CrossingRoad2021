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
    yMap = 5*lane;
    Time = 0;
    frameTime = 1;
    level = 1;
    obsList.resize(lane);
    player.setPosition(30,10);
}

Game::Game(int xMap, int lane)
{
    this->xMap = xMap;
    this->lane = lane;
    yMap = 5*lane;
    Time = 0;
    level = 1;
}

void Game::updateFrame()
{
    Time += frameTime;
    for (int i = 0; i < obsList.size(); i++)
    {
        for (int j = 0; j < obsList[i].size(); j++) {
            if (Time % obsList[i][j]->getSpeed() == 0)
            {
                obsList[i][j]->updatePosition();
                if (obsList[i][j]->getXPos() + obsList[i][j]->getLength() - 1 >= xMap) {
                    obsList[i][j]->popShape();
                }
            }

            if (obsList[i][j]->getXPos() == xMap)
                obsList[i].erase(obsList[i].begin() + j);

        }

    }
    addObstacle();
    player.takeKBinput(*this);
}

void Game::draw()
{
    GotoXY(101,0);
    cout << Time;

    player.draw();
    for (int i = 0; i < obsList.size(); ++i)
        for (int j = 0; j < obsList[i].size(); j++)
            obsList[i][j]->draw();
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
   
    
}

void Game::outputObs()
{
    for (int i = 0; i < obsList.size(); ++i)
        for(int j = 0; j < obsList[i].size(); j++)
            obsList[i][j]->output();
}

bool Game::checkCollision()
{
    for(int i = 0; i < obsList.size(); ++i)
    {
        for (int j = 0; j < obsList[i].size(); j++) {
            if (player.getYPos() + player.getWidth() >= obsList[i][j]->getLane() * 5)
            {
                if (obsList[i][j]->getXPos() + obsList[i][j]->getLength() >= player.getXPos() || player.getXPos() + player.getLength() >= obsList[i][j]->getXPos())
                {
                    return true;
                }
            }

            if (obsList[i][j]->getLane() * 5 + obsList[i][j]->getWidth() >= player.getYPos())
            {
                if (player.getXPos() + player.getLength() >= obsList[i][j]->getXPos() || obsList[i][j]->getXPos() + obsList[i][j]->getLength() >= player.getXPos())
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void Game::addObstacle() {
    for (int j = 0; j < lane; j++) {
        if (rand() % 70 == 0)
        {
            Obstacles* obs = nullptr;
            if (rand() % 4 == 0)
                obs = new Dinausor(3, j, 9, 5, (rand() % 3 + 2));
            else if (rand() % 3 == 1)
                obs = new Car(3, j, 15, 3, (rand() % 3 + 2));
            else if (rand() % 3 == 2)
                obs = new Truck(3, j, 24, 5, (rand() % 3 + 2));
            else
                obs = new Bike(3, j, 11, 3, (rand() % 3 + 2));

            for (int k = 0; k < obsList[j].size(); k++)
                if (obs->getSpeed() < obsList[j][k]->getSpeed() || obs->getLength() + 2 >= obsList[j][k]->getXPos())
                    return;
            obsList[j].push_back(obs);
        }
    }
}
