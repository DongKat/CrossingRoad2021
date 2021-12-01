#ifndef _CROSSING_ROAD_H_
#define _CROSSING_ROAD_H_

#include <iostream>
#include <Windows.h>
#include <vector>
#include <thread>
#include <conio.h>

using namespace std;

class Game;
class Player
{
    private:
        int xPos;
        int yPos;
        int length, width;

    public:
        Player();
        Player(int xPos, int yPos, int length, int width);
        void draw();
        void takeKBinput(Game game);
        void setPosition(int xPos, int yPos);
        int getXPos();
        int getYPos();
        int getLength();
        int getWidth();
};

class Obstacles
{
    private:
        int xPos;
        int lane;
        int length, width;
        int speed;
    public:
        Obstacles(int xPos, int lane, int length, int width, int speed);
        void updatePosition();
        void draw();
        int getXPos();
        int getLane();
        void setXPos(int xPos);
        void output();
        int getSpeed();
        int getLength();
        int getWidth();

};

class Game //Frame
{
    private:
        int xMap, yMap;
        int lane;
        int Time;
        int frameTime;
        int level;
        Player player;
        vector<Obstacles> obsList;

    public:
        Game();
        Game(int xMap, int lane);
        void updateLevel();
        void updateFrame();
        void InitDraw();
        void draw();
        int getTime();
        void outputObs();
        bool checkCollision();
        friend void Player::takeKBinput(Game game);
        //void addObsticle(Obstacles obs); 
};

#endif 
