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
	virtual void draw() = 0;
	virtual void popShape() = 0;
	int getXPos();
	int getLane();
	void setXPos(int xPos);
	void output();
	int getSpeed();
	int getLength();
	int getWidth();
};

class Dinausor : public Obstacles
{
private:
	vector<string> shape;
public:
	Dinausor(int xPos, int lane, int length, int width, int speed);
	void popShape();
	void draw();
};

class Car : public Obstacles
{
private:
	vector<string> shape;
public:
	Car(int xPos, int lane, int length, int width, int speed);
	void popShape();
	void draw();
};

class Bike : public Obstacles
{
private:
	vector<string> shape;
public:
	Bike(int xPos, int lane, int length, int width, int speed);
	void popShape();
	void draw();
};

class Truck : public Obstacles
{
private:
	vector<string> shape;
public:
	Truck(int xPos, int lane, int length, int width, int speed);
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
	//void addObsticle(Obstacles obs); 
};

#endif 
