#ifndef _CROSSING_ROAD_H_
#define _CROSSING_ROAD_H_

#include <iostream>
#include <Windows.h>
#include <vector>
#include <thread>
#include <conio.h>

using namespace std;

class Player
{
    
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
        void setXPos(int xPos);
        void output();
        int getSpeed();
};

class Game //Frame
{
    private:
        int xMap, yMap;
        int lane;
        int Time;
        int frameTime;
        int level;
        vector<Obstacles> obsList;

    public:
        Game();
        Game(int xMap, int lane);
        void updateLevel();
        void updateFrame();
        void draw();
        int getTime();
        void outputObs();
        //void addObsticle(Obstacles obs); 
};

#endif 
