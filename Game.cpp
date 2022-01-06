#include "CrossingRoad.h"
#include "BuildConsole.h"
#define PROOF "CROSSROADSAVE"

Game::Game()
{
	xMap = 120;
	lane = 6;
	yMap = 6 * (lane + 1);
	Time = 0;
	frameTime = 1;
	level = 1;
	trafficLight = true;    // DCat: True = Green, False = red
	obsList.resize(lane);
	player.setPosition(60, 39);
}

Game::Game(int xMap, int lane)
{
	this->xMap = xMap;
	this->lane = lane;
	yMap = 6 * lane;
	Time = 0;
	level = 1;
}

void Game::updateFrame()
{
	Time += frameTime;
	for (int i = 0; i < obsList.size(); i++)
	{
		for (int j = 0; j < obsList[i].size(); j++)
		{
			if (Time % obsList[i][j]->getSpeed() == 0)
			{
				obsList[i][j]->updatePosition();
				if (obsList[i][j]->getXPos() + obsList[i][j]->getLength() - 1 >= xMap)
				{
					obsList[i][j]->popShape();
				}
			}

			if (obsList[i][j]->getXPos() == xMap)
				obsList[i].erase(obsList[i].begin() + j);

		}

	}
	/*if (player.levelUp()) {
		GotoXY()
		player.setPosition(60, 39);
		updateLevel();
	}*/
	addObstacle();
	player.takeKBinput(*this);
}

void Game::draw()
{
	GotoXY(101, 0);
	cout << Time;

	player.draw();
	for (int i = 0; i < obsList.size(); ++i)
		for (int j = 0; j < obsList[i].size(); j++)
			obsList[i][j]->draw();
}

void Game::InitDraw()
{
	GotoXY(95, 0);
	cout << "Time: ";
	for (int i = 0; i < lane - 1; i++) {
		GotoXY(3, 7 + i * 6);
		for (int i = 0; i < 8; i++)
			cout << "_________      ";
	}
	GotoXY(1, 1);
	TextColor(2);
	for (int i = 0; i <= xMap - 2; i++) {

		cout << char(22);
	}
	GotoXY(1, 37);
	for (int i = 0; i <= xMap - 2; i++)
		cout << char(22);
	TextColor(7);
	for (int i = 0; i <= yMap + 1; ++i)
	{
		GotoXY(0, i);
		cout << char(221) << endl;
		GotoXY(xMap, i);
		cout << char(222) << endl;
	}
	for (int i = 0; i <= xMap; ++i)
	{
		GotoXY(i, 0);
		cout << char(223);
		GotoXY(i, yMap + 2);
		cout << char(223);
	}
}

int Game::getTime()
{
	return Time;
}

void Game::updateLevel()
{
	level++;
}

void Game::outputObs()
{
	for (int i = 0; i < obsList.size(); ++i)
		for (int j = 0; j < obsList[i].size(); j++)
			obsList[i][j]->output();
}

bool Game::checkCollision()
{
	int lane = player.getYPos() / 6;
	if (lane < 6) {
		for (int i = 0; i < obsList[lane].size(); i++) {
			for (int j = player.getXPos(); j < player.getXPos() + player.getLength(); j++) {
				if (j >= obsList[lane][i]->getXPos() && j < obsList[lane][i]->getXPos() + obsList[lane][i]->getLength() - 2) {
					return true;
				}
			}
		}
	}
	return false;
}

void Game::addObstacle() {
	// Lane 0, 1, 2 for Vehicles
	// Lane 3, 4, 5 for Animals

	int speed = 2;
	for (int j = 0; j < lane; j++)
	{
		Obstacles* obs = nullptr;
		if (rand() % (300 / level) == 0)
		{
			switch (j) {
			case 0:
			{
				obs = new Car(3, 0, 15, 3, speed);
				break;
			}
			case 1:
			{
				obs = new Truck(3, 1, 24, 5, speed);
				break;
			}
			case 2:
			{
				obs = new Bike(3, 2, 11, 3, speed);
				break;
			}
			case 3:
			{
				obs = new Dinausor(3, 3, 9, 5, speed);
				break;
			}
			case 4:
			{
				obs = new Dinausor(3, 4, 9, 5, speed);
				break;
			}
			case 5:
			{
				obs = new Dinausor(3, 5, 9, 5, speed);
				break;
			}
			default:
			{
				break;
			}
			}
			for (int k = 0; k < obsList[j].size(); k++)
				if (obs->getSpeed() < obsList[j][k]->getSpeed() || obs->getLength() + 2 >= obsList[j][k]->getXPos())
					return;
			obsList[j].push_back(obs);
		}
	}

	/*for (int j = 0; j < lane; j++)
	{
		if (rand() % (300 / level) == 0)
		{
			Obstacles* obs = nullptr;
			if (rand() % 4 == 0)
				obs = new Dinausor(3, j, 9, 5, (rand() % 6 + 5));
			else if (rand() % 3 == 1)
				obs = new Car(3, j, 15, 3, (rand() % 6 + 5));
			else if (rand() % 3 == 2)
				obs = new Truck(3, j, 24, 5, (rand() % 6 + 5));
			else
				obs = new Bike(3, j, 11, 3, (rand() % 6 + 5));

			for (int k = 0; k < obsList[j].size(); k++)
				if (obs->getSpeed() < obsList[j][k]->getSpeed() || obs->getLength() + 2 >= obsList[j][k]->getXPos())
					return;
			obsList[j].push_back(obs);
		}
	}*/
}
void Game::saveGame(string name)
{
	// Get save file name
	string name;                            // This way so I don't have to deal with char*
	getline(cin, name);
	FILE* file = fopen(name.c_str(), "wb");	// Write file in binary mode
	if (!file)
		throw runtime_error("Oh no, something go wrong. Game::saveGame");

	fwrite(PROOF, sizeof(char), strlen(PROOF), file);   // Write certificate
	fwrite(&level, sizeof(int), 1, file);               // Write level

	fclose(file);
}

void Game::loadGame(string name)
{
	// Get save file name
	getline(cin, name);
	FILE* file = fopen(name.c_str(), "rb");

	if (!file)
		throw runtime_error("Oh no, something go wrong. Game::loadGame");

	char token[50];
	fread(token, sizeof(char), strlen(PROOF), file);
	token[strlen(PROOF)] = '\0';
	if (strcmp(token, PROOF)) {
		fclose(file);
		throw runtime_error("Oh no, something go wrong. Game::loadGame");
	}

	fread(&level, sizeof(int), 1, file);        // Read saved game level

	fclose(file);
}
