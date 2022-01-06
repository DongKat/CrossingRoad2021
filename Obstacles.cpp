#include "CrossingRoad.h"

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
	/*if (lane % 2 == 0)*/
	xPos += 1;
	/*else
		xPos -= 1;*/
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
	cout << "xPos: " << xPos << " lane: " << lane << " length: " << length << " width: " << width << "speed: " << speed << endl;
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

void Obstacles::clearObstacle()
{
	for (int i = 0; i < this->width; i++)
	{
		GotoXY(xPos - 1, 6 + lane * 6 - i);
		for (int j = 0; j < this->length; j++)
			cout << " ";
	}
}

Dinausor::Dinausor(int xPos, int lane, int length, int width, int speed) : Obstacles(xPos, lane, length, width, speed) {
	shape.resize(5);	
	shape[0] = "    ____ ";
	shape[1] = "   | o__|";
	shape[2] = " \\_/  |__";
	shape[3] = " \\____/  ";
	shape[4] = "   |_|_  ";
}

void Dinausor::popShape() {
	for (int i = 0; i < 5; i++) {
		shape[i].pop_back();
	}
	length--;
}

void Dinausor::draw()
{
	TextColor(11);
	for (int i = 0; i < 5; i++) {
		GotoXY(getXPos() - 1, getLane() * 6 + i + 2);
		cout << shape[i];
	}
	TextColor(7);
}

Car::Car(int xPos, int lane, int length, int width, int speed) : Obstacles(xPos, lane, length, width, speed) {
	shape.resize(3);
	char i = 22;
	shape[0] = "     _____     ";
	shape[1] = shape[1] + "  __/    " + char(254) + "\\___ ";
	shape[2] = shape[2] + " " + char(192) + i + char(233) + i + i + i + i + i + i + i + char(233) + i + i + char(188);
}

void Car::popShape() {
	for (int i = 0; i < 3; i++) {
		shape[i].pop_back();
	}
	length--;
}

void Car::draw()
{
	TextColor(14);
	for (int i = 0; i < 3; i++) {
		GotoXY(getXPos() - 1, getLane() * 6 + i + 4);
		cout << shape[i];
	}
	TextColor(7);
}

Bike::Bike(int xPos, int lane, int length, int width, int speed) : Obstacles(xPos, lane, length, width, speed) {
	shape.resize(3);
	shape[0] = "     o__   ";
	shape[1] = "    /_  \\  ";
	shape[2] = shape[2] + " (" + char(15) + ")  \\ (" + char(15) + ")";
}


void Bike::popShape() {
	for (int i = 0; i < 3; i++) {
		shape[i].pop_back();
	}
	length--;
}

void Bike::draw()
{
	TextColor(14);
	for (int i = 0; i < 3; i++) {
		GotoXY(getXPos() - 1, getLane() * 6 + i + 4);
		cout << shape[i];
	}
	TextColor(7);
}
Truck::Truck(int xPos, int lane, int length, int width, int speed) : Obstacles(xPos, lane, length, width, speed) {
	shape.resize(5);
	char i = 196;
	shape[0]= "  ______________        ";
	shape[1]= " |              |___    ";
	shape[2]= shape[2] + " |              | " + char(254) + " |__ ";
	shape[3]= " |______________|      |";
	shape[4]= shape[4] +" " + char(192) + i + i + i + "(o)" + i + i + i + i + i + i + i + i + i + i + i + "(o)" + i + char(188);
}

void Truck::popShape() {
	for (int i = 0; i < 5; i++) {
		shape[i].pop_back();
	}
	length--;
}

void Truck::draw()
{
	TextColor(11);
	for (int i = 0; i < 5; i++) {
		GotoXY(getXPos() - 1, getLane() * 6 + i + 2);
		cout << shape[i];
	}
}

Kuma::Kuma(int xPos, int lane, int length, int width, int speed) : Obstacles(xPos, lane, length, width, speed)
{
	shape.resize(4);
	shape[0] = "    /|/|";
	shape[1] = "  /00  |";
	shape[2] = " |/^^\\ |";
	shape[3] = "  \\m_m_|";
}
void Kuma::popShape()
{
	for (int i = 0; i < 4; i++) {
		shape[i].pop_back();
	}
	length--;
}
void Kuma::draw()
{
	// # RGB Bear (Totoro)
	TextColor(rand() % 15);
	for (int i = 0; i < 4; i++) {
		GotoXY(getXPos()-1, getLane() * 6 + i + 3);
		cout << shape[i];
	}
	TextColor(15);
}
Bird::Bird(int xPos, int lane, int length, int width, int speed) : Obstacles(xPos, lane, length, width, speed)
{
	shape.resize(5);
	shape[0] = "⣿⣿⡇⠀⠀⢸⣿⢰⣿⡆⠀⣾⣿⡆⠀⣾⣷ ⣿⣿⡇⠀⠀⣿⣿⡇";
	shape[1] = "⣿⣿⡇⠀⠀⢸⣿⠘⣿⣿⣤⣿⣿⣿⣤⣿⡇⢻⣿⡇⠀⠀⣿⣿⡇⠀";
	shape[2] = "⣿⣿⡇⠀⠀⢸⡿⠀⢹⣿⣿⣿⣿⣿⣿⣿⠁⢸⣿⣇⠀⢀⣿⣿⠇⠀";
	shape[3] = "⠙⢿⣷⣶⣶⡿⠁⠀⠈⣿⣿⠟⠀⣿⣿⠇⠀⠈⠻⣿⣶⣾⡿⠋⠀⠀";
}
void Bird::popShape()
{
	for (int i = 0; i < 4; i++) {
		shape[i].pop_back();
	}
	length--;
}
void Bird::draw()
{
	// # RGB Bear (Totoro)
	srand(time(NULL));
	TextColor(rand() % 15);
	for (int i = 0; i < 5; i++) {
		GotoXY(getXPos() - 1, getLane() * 6 + i + 2);
		cout << shape[i];
	}
}
	TextColor(7);
}	  