#ifndef _CROSSING_ROAD_H_
#define _CROSSING_ROAD_H_

#include <iostream>
#include <Windows.h>
#include <vector>
#include <thread>
#include <string>
#include <conio.h>
#include "BuildConsole.h"
#include "Sound.h"
#include "BuildMenu.h"

using namespace std;

class Game;
class Player
{
private:
	int xPos;
	int yPos;
	int length, width;
	bool levelup;
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
	void clearPlayer();
	bool levelUp();
	
	friend class Game;
	void resetLevelUp();
};

class Obstacles
{
protected:
	vector<string> shape;
	int xPos;
	int lane;
	int length, width;
	int speed;
public:
	Obstacles(int xPos, int lane, int length, int width, int speed);
	void updatePosition();
	virtual void draw() = 0;
	virtual void popShape() = 0;
	int getXPos();
	int getLane();
	void setXPos(int xPos);
	void output();
	int getSpeed();
	int getLength();
	int getWidth();
	void clearObstacle();
};

class Dinausor : public Obstacles
{

public:
	Dinausor(int xPos, int lane, int length, int width, int speed);
	void popShape();
	void draw();
};

class Car : public Obstacles
{

public:
	Car(int xPos, int lane, int length, int width, int speed);
	void popShape();
	void draw();
};

class Bike : public Obstacles
{

public:
	Bike(int xPos, int lane, int length, int width, int speed);
	void popShape();
	void draw();
};

class Truck : public Obstacles
{

public:
	Truck(int xPos, int lane, int length, int width, int speed);
	void popShape();
	void draw();
};

class Bird : public Obstacles
{
public:
	Bird(int xPos, int lane, int length, int width, int speed);
	void popShape();
	void draw();
};

class Game //Frame
{
private:
	int xMap, yMap;
	int lane;
	int Time;
	int frameTime;
	int level;
	bool trafficLight;
	Player player;
	vector<vector<Obstacles*>> obsList;
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
	void addObstacle();
	friend void Player::takeKBinput(Game game);
	void loadGame(string name);
	void saveGame(string name);
	void levelUpAnimation();
	void gameOverAnimation();
};

#endif 
