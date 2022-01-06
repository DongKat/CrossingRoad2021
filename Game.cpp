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
	player = new Player;
	player->setPosition(60, 39);
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
	if (player->levelUp()) 
	{
		levelUpAnimation();
		InitDraw();
		updateLevel();
	}
	addObstacle();
	player->takeKBinput(this);
}

void Game::draw()
{
	GotoXY(122, 0);
	cout << "Time: " << Time / 40;
	GotoXY(122, 2);
	cout << "Level: " << level;
	GotoXY(122, 4);
	cout << "Player: x: " << player->getXPos() << " y: " << player->getYPos();

	player->draw();
	for (int i = 0; i < lane; i++)
		for (int j = 0; j < obsList[i].size(); j++)
			obsList[i][j]->draw();
}

void Game::InitDraw()
{
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

void Game::levelUpAnimation()
{
	for(int i = 0; i < 3; ++i)
	{
		clrscr();
		GotoXY(15, 20 - 5);	TextColor(3*i + 1); cout << "$$\\       $$$$$$$$\\ $$\\    $$\\ $$$$$$$$\\ $$\\             $$\\   $$\\ $$$$$$$\\  ";
		GotoXY(15, 21 - 5);	TextColor(3*i + 1); cout << "$$ |      $$  _____|$$ |   $$ |$$  _____|$$ |            $$ |  $$ |$$  __$$\\ ";
		GotoXY(15, 22 - 5);	TextColor(3*i + 1); cout << "$$ |      $$ |      $$ |   $$ |$$ |      $$ |            $$ |  $$ |$$ |  $$ |";
		GotoXY(15, 23 - 5);	TextColor(3*i + 1); cout << "$$ |      $$$$$\\    \\$$\\  $$  |$$$$$\\    $$ |            $$ |  $$ |$$$$$$$  |";
		GotoXY(15, 24 - 5);	TextColor(3*i + 1); cout << "$$ |      $$  __|    \\$$\\$$  / $$  __|   $$ |            $$ |  $$ |$$  ____/ ";
		GotoXY(15, 25 - 5);	TextColor(3*i + 1); cout << "$$ |      $$ |        \\$$$  /  $$ |      $$ |            $$ |  $$ |$$ |      ";
		GotoXY(15, 26 - 5);	TextColor(3*i + 1); cout << "$$$$$$$$\\ $$$$$$$$\\    \\$  /   $$$$$$$$\\ $$$$$$$$\\       \\$$$$$$  |$$ |      ";
		GotoXY(15, 27 - 5);	TextColor(3*i + 1); cout << "\\________|\\________|    \\_/    \\________|\\________|       \\______/ \\__|      ";
		Sleep(700);
		clrscr();
		Sleep(400);
	}

	GotoXY(45,20);
	char levelA[] = "CURRENT LEVEL: ";
	for(int i = 0; i < strlen(levelA); i++)
	{
		cout << levelA[i];
		Sleep(20);
	}
	cout << level + 1;
	Sleep(300);
	clrscr();
}

void Game::gameOverAnimation()
{
	player->drawDead();
	Sleep(1500);

	for(int i = 0; i < 3; ++i)
	{
		clrscr();
		GotoXY(15, 20 - 5);	TextColor(3*i + 1); cout << " $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\        $$$$$$\\  $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\  ";
		GotoXY(15, 21 - 5);	TextColor(3*i + 1); cout << "$$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|      $$  __$$\\ $$ |   $$ |$$  _____|$$  __$$\\ ";
		GotoXY(15, 22 - 5);	TextColor(3*i + 1); cout << "$$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |            $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |";
		GotoXY(15, 23 - 5);	TextColor(3*i + 1); cout << "$$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\          $$ |  $$ |\\$$\\  $$  |$$$$$\\    $$$$$$$  |";
		GotoXY(15, 24 - 5);	TextColor(3*i + 1); cout << "$$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|         $$ |  $$ | \\$$\\$$  / $$  __|   $$  __$$< ";
		GotoXY(15, 25 - 5);	TextColor(3*i + 1); cout << "$$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |            $$ |  $$ |  \\$$$  /  $$ |      $$ |  $$ |";
		GotoXY(15, 26 - 5);	TextColor(3*i + 1); cout << "\\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\        $$$$$$  |   \\$  /   $$$$$$$$\\ $$ |  $$ |";
		GotoXY(15, 27 - 5);	TextColor(3*i + 1); cout << " \\______/ \\__|  \\__|\\__|     \\__|\\________|       \\______/     \\_/    \\________|\\__|  \\__|";
		Sleep(1200);
		clrscr();
		Sleep(400);
	}
}

int Game::getTime()
{
	return Time;
}

void Game::updateLevel()
{
	player->clearPlayer();
	player->setPosition(60, 39);
	player->resetLevelUp();
	for (int i = 0; i < lane; i++) {
		for (int j = 0; j < obsList[i].size(); j++) {
			obsList[i][j]->clearObstacle();
		}
		obsList[i].clear();
	}
	GotoXY(122, 0);
	cout << "   ";
	Time = 0;
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
	int lane = player->getYPos() / 6;
	if (lane < 6) {
		for (int i = 0; i < obsList[lane].size(); i++) {
			for (int j = player->getXPos(); j < player->getXPos() + player->getLength(); j++) {
				if (j >= obsList[lane][i]->getXPos() && j < obsList[lane][i]->getXPos() + obsList[lane][i]->getLength() - 1) {
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

	int speed = 11 - level * 2;
	if (speed <= 0)
		speed = 1;
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
				if (obs->getSpeed() < obsList[j][k]->getSpeed() || obs->getLength() + 2 >= obsList[j][k]->getXPos()) {
					delete obs;
					return;
				}
			obsList[j].push_back(obs);
		}
	}

	/*for (int j = 0; j < lane; j++)
	{
		if (rand() % (300 / level) == 0)5
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
	/*string name;	*/	// This way so I don't have to deal with char*
	FILE* file = fopen(name.c_str(), "wb");	// Write file in binary mode
	if (!file)
		throw runtime_error("Save error");

	int tmp_x, tmp_y;

	fwrite(PROOF, sizeof(char), strlen(PROOF), file);   // Write certificate
	fwrite(&level, sizeof(int), 1, file);               // Write level

	
	fwrite(&player->xPos, sizeof(int), 1, file);			// Write player position
	fwrite(&player->yPos, sizeof(int), 1, file);			// Write player position
	fwrite(&lane, sizeof(int), 1, file);			// Write number of lanes, which always is 6 tho
	for (int i = 0; i < lane; i++)
	{
		tmp_x = obsList[i].size();
		fwrite(&tmp_x, sizeof(int), 1, file);
		for (int j = 0; j < obsList[i].size(); j++)
		{
			tmp_x = obsList[i][j]->getXPos();
			fwrite(&tmp_x, sizeof(int), 1, file);	// Write obstacle XPos
		}
	}
	fwrite(&trafficLight, sizeof(bool), 1, file); // Write traffic light
	fclose(file);
}

void Game::loadGame(string name)
{
	// Get save file name
	FILE* file = fopen(name.c_str(), "rb");

	if (!file)
		throw runtime_error("Load Error");

	char token[50];
	fread(token, sizeof(char), strlen(PROOF), file);
	token[strlen(PROOF)] = '\0';
	if (strcmp(token, PROOF)) {
		fclose(file);
		throw runtime_error("Load Error");
	}

	int tmp_x, tmp_y;
	int speed = 11 - level * 2;
	if (speed <= 0)
		speed = 1;
	fread(&level, sizeof(int), 1, file);        // Read saved game level

	fread(&player->xPos, sizeof(int), 1, file);			// Read player x position
	fread(&player->yPos, sizeof(int), 1, file);			// Read player y position
	fread(&lane, sizeof(int), 1, file);				// Read number of lane, tho it's default 6

	// Clear screen
	

	obsList.resize(lane);
	Obstacles* obs = nullptr;
	for (int i = 0; i < lane; i++)
	{
		obsList[i].clear();
		fread(&tmp_x, sizeof(int), 1, file);		// Read Lane size
		for (int j = 0; j < tmp_x; j++)
		{
			fread(&tmp_y, sizeof(int), 1, file);	// Read obstacle XPos, pls don't mind tmp_y, it means second temp var
			switch (i) {
			case 0:
			{
				obs = new Car(tmp_y, 0, 15, 3, speed);
				break;
			}
			case 1:
			{
				obs = new Truck(tmp_y, 1, 24, 5, speed);
				break;
			}
			case 2:
			{
				obs = new Bike(tmp_y, 2, 11, 3, speed);
				break;
			}
			case 3:
			{
				obs = new Dinausor(tmp_y, 3, 9, 5, speed);
				break;
			}
			case 4:
			{
				obs = new Dinausor(tmp_y, 4, 9, 5, speed);
				break;
			}
			case 5:
			{
				obs = new Dinausor(tmp_y, 5, 9, 5, speed);
				break;
			}
			default:
			{
				break;
			}
			}
			obsList[i].push_back(obs);
		}
	}
	fread(&trafficLight, sizeof(bool), 1, file); // Read traffic light state

	fclose(file);
}
