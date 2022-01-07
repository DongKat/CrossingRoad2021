#include "CrossingRoad.h"

void GotoXY(int x, int y);

Player::Player()
{
	xPos = 0;
	yPos = 0;
	length = 7;
	width = 4;
	levelup = false;
}

Player::Player(int xPos, int yPos, int length, int width)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->length = length;
	this->width = width;
}

void Player::draw()
{

	//// Human looks like this █
	//GotoXY(xPos, yPos);     cout << char(219);

	// Or human looks like this:
	/*
	  / \ <- party hat
	 ('_')
	/|   |\
	 |___|
	 |_  |_
	*/

	/*
	"  / \\  ";
	" ('_')	";
	"/|   |\\";
	" |||||	";
	" |_  |_"
	Dancing
	"  / \\	";
	"\\('_')/";
	" |   |	";
	" |||||	";
	" |_  |_";
	*/
	GotoXY(xPos, yPos);     cout << " ('_') ";
	GotoXY(xPos, yPos + 1); cout << "/|   |\\";
	GotoXY(xPos, yPos + 2); TextColor(4); cout << " ||||| "; TextColor(15);
	GotoXY(xPos, yPos + 3); cout << " |_  |_";
}

void Player::drawDead()
{
	GotoXY(xPos, yPos);     cout << " (x_x) ";
	GotoXY(xPos, yPos + 1); cout << "/|   |\\";
	GotoXY(xPos, yPos + 2); TextColor(4); cout << " ||||| "; TextColor(15);
	GotoXY(xPos, yPos + 3); cout << " |_  |_";
}
void Player::drawBoom()
{
	GotoXY(xPos, yPos + 4);		cout << "  ____.,/       \~,._____";
	Sleep(100);
	GotoXY(xPos, yPos + 3);		cout << "      `--_--_--_--'   ";
	Sleep(100);
	GotoXY(xPos, yPos + 2);		cout << "      .-=||  | |=-.   ";
	GotoXY(xPos, yPos + 1);		cout << "   ```--. . , ; .--'''       ";
	Sleep(100);
	GotoXY(xPos, yPos + 0);		cout << " \\._               _./  ";
	Sleep(100);
	GotoXY(xPos, yPos - 1);		cout << " (                    >)";
	Sleep(100);
	GotoXY(xPos, yPos - 2);		cout << "  _--                -_";
	Sleep(100);
	GotoXY(xPos, yPos - 3);		cout << "    _.-^^---....,,--_ ";
	
}

void Player::takeKBinput(Game* game)
{
	if (game->Time == 240) 
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	if (game->Time > 240) {
		if (kbhit())
		{
			char input = getch();
			if ((input == 'a' || input == 'A') && xPos > 5)
			{
				clearPlayer();
				GotoXY(xPos, yPos);
				cout << " ";
				xPos -= 3;
			}
			else if ((input == 'd' || input == 'D') && xPos < game->xMap - this->length - 5)
			{
				clearPlayer();
				GotoXY(xPos, yPos);
				cout << " ";
				xPos += 3;
			}
			else if (input == 'w' || input == 'W') {
				if (yPos > 3) {
					clearPlayer();
					GotoXY(xPos, yPos);
					cout << " ";
					yPos -= 6;
				}
				else
					levelup = true;
			}
			else if ((input == 's' || input == 'S') && yPos <= game->yMap - this->width)
			{
				clearPlayer();
				GotoXY(xPos, yPos);
				cout << " ";
				yPos += 6;
			}
			else if ((input == 'l' || input == 'L')) // Hit Load game
			{
				try
				{
					string temp;
					TextColor(12);		GotoXY(128, 8); cout << "LOAD GAME ";
					TextColor(6);		GotoXY(128, 10); cout << "Enter save file name: " << endl;
					cin.clear();
					ShowConsoleCursor(true);
					GotoXY(128, 12);	getline(cin, temp);
					ShowConsoleCursor(false);
					TextColor(15);
					game->loadGame(temp);
					clrscr();
					game->InitDraw();
				}
				catch (runtime_error e)
				{
					GotoXY(128, 15); cout << e.what();
					Sleep(1000);
					GotoXY(128, 15); cout << "           ";
				}
				GotoXY(128, 8); cout << "                         ";
				GotoXY(128, 10); cout << "                        ";
				GotoXY(128, 12); cout << "                        ";
			}
			else if ((input == 't' || input == 'T')) // Hit Save game
			{
				try
				{
					string temp;
					TextColor(12); GotoXY(128, 8); cout << "SAVE GAME ";
					TextColor(6); GotoXY(128, 10); cout << "Enter save file name: " << endl;
					cin.clear();
					ShowConsoleCursor(true);
					GotoXY(128, 12);	getline(cin, temp);
					ShowConsoleCursor(false);
					TextColor(15);
					game->saveGame(temp);
					GotoXY(128, 27);	cout << "                      ";
					GotoXY(128, 30);	cout << "                      ";
					GotoXY(128, 32);	cout << "                      ";
					// Draw instruction board again
					drawBoard(128, 26, 144, 35);
					GotoXY(130, 27);	cout << "INSTRUCTION";
					GotoXY(130, 28);	cout << "W: Up";
					GotoXY(130, 29);	cout << "S: Down";
					GotoXY(130, 30);	cout << "A: Left";
					GotoXY(130, 31);	cout << "D: Right";
					GotoXY(130, 32);	cout << "P: Pause";
					GotoXY(130, 33);	cout << "T: Save";
					GotoXY(130, 34);	cout << "L: Load";
				}
				catch (runtime_error e)
				{
					GotoXY(128, 15); cout << e.what();
				}
				GotoXY(128, 8); cout << "                         ";
				GotoXY(128, 10); cout << "                        ";
				GotoXY(128, 12); cout << "                        ";

			}
			else if ((input == 'p' || input == 'P'))
			{
				int i = 0;
				TextColor(12); GotoXY(133, 8); cout << "PAUSE ";
				TextColor(6); GotoXY(133, 10); cout << "RESUME " << endl;
				TextColor(15); GotoXY(133, 12); cout << "EXIT  " << endl;

				while (true)
				{
					input = getch();
					if (input == 'w' || input == 'W' || input == 80)
					{
						if (i < 1) i++;
						else i = 0;
					}
					if (input == 's' || input == 'S' || input == 72)
					{
						if (i > 0) i--;
						else i = 1;
					}
					if (i == 0)
					{
						if (input == 13)
						{
							// Resume 
							GotoXY(133, 8); cout << "          ";
							GotoXY(133, 10); cout << "          ";
							GotoXY(133, 12); cout << "          ";
							break;
						}
						TextColor(6);
						GotoXY(133, 10); cout << "RESUME " << endl;
						TextColor(15);
						GotoXY(133, 12); cout << "EXIT  " << endl;
					}
					if (i == 1)
					{
						if (input == 13)
						{
							// Exit to main memu
							throw "lala";
							break;
						}
						TextColor(15);
						GotoXY(133, 10); cout << "RESUME " << endl;
						TextColor(6);
						GotoXY(133, 12); cout << "EXIT  " << endl;
						TextColor(15);
					}
				}
			}
			else if (input == 27) // Hit ESC key
			{
				// Exit to main memu
				system("pause");
			}
		}
	}
}

void Player::setPosition(int xPos, int yPos)
{
	this->xPos = xPos;
	this->yPos = yPos;
}

int Player::getXPos()
{
	return xPos;
}

int Player::getYPos()
{
	return yPos;
}

int Player::getLength()
{
	return length;
}

int Player::getWidth()
{
	return width;
}

void Player::clearPlayer()
{
	for (int i = 0; i < this->width; i++)
	{
		GotoXY(xPos, yPos + i);
		for (int j = 0; j < this->length; j++)
			cout << " ";
	}
}
bool Player::levelUp()
{
	return levelup;
}

void Player::resetLevelUp() {
	levelup = false;
}