#include "BuildMenu.h"

Menu::Menu(Sound* s)
{
	music = s;
}
void Menu::drawMenu()
{
	clrscr();
	drawTitle();
	drawBoard(37, 17, 118, 35);
	drawBoard(52, 17, 118, 35);
	drawBoard(37, 36, 72, 38);
	TextColor(3);
	GotoXY(39, 37); cout << "USE ARROWS TO NAVIGATE THE MENU";
	TextColor(15);
}
void Menu::drawTitle()
{	
	TextColor(9);
	for (int i = 0; i < 6; i++)
	{
		GotoXY(16, 5 + i);
		cout << title[i];
	}
	TextColor(12);
	for (int i = 6; i < 12; i++)
	{
		GotoXY(16, 5 + i);
		cout << title[i];
	}
	TextColor(15);
}

void Menu::drawChoice()
{

	GotoXY(40, 19);
	cout << "MAIN MENU"; TextColor(15);

	for (int i = 0; i < 6; ++i)
	{
		GotoXY(40, y[i] + 5);
		cout << list[i];
	}
}
void Menu::clear()
{
	for (int i = 14; i < 30; ++i)
	{
		GotoXY(53, i + 5);
		cout << "                                                                 ";
	}
}
int Menu::updateChoice()
{
	int i = 0;
	char x;
	while (1)
	{
		clear();
		GotoXY(39, y[i] + 5);
		TextColor(14);
		cout << ">" << list[i];
		TextColor(15);
		drawDescription(i);
		x = _getch();
		if (x == -32)
			x = _getch();
		switch (x)
		{
		case 72: {
			if (i > 0)
			{
				GotoXY(39, y[i] + 5);
				TextColor(15);
				cout << " " << list[i];
				i--;
			}
			break;
		}
		case 80: {
			if (i < 5) {
				GotoXY(39, y[i] + 5);
				TextColor(15);
				cout << " " << list[i];
				i++;
			}
			break;
		}
		case 13: {
			if (i == 0)
			{
				return 0;
			}
			if (i == 1)
			{
				return 1;
			}
			if (i == 5) return 5;
			break;
		}
		default: break;
		}
	}
}

string Menu::LoadGame()
{
	string temp;
	GotoXY(54, 21); cout << "                                                   ";
	GotoXY(54, 21);	cout << "Enter your save file name:";
	GotoXY(54, 23); cout << "                                                   ";
	ShowConsoleCursor(true);
	GotoXY(54, 23); getline(cin, temp);
	ShowConsoleCursor(false);

	return temp;
}

void Menu::drawDescription(int x)
{

	switch (x)
	{
	case 0:
	{
		GotoXY(80, 19);
		cout << "DESCRIPTION";
		GotoXY(54, 21);
		cout << "Start a new game!";
		break;
	}
	case 1:
	{
		GotoXY(80, 19);
		cout << "DESCRIPTION";
		GotoXY(54, 21);
		cout << "Start with an existed game!";
		break;
	}
	case 2:
	{
		GotoXY(80, 19);
		cout << "DESCRIPTION";
		GotoXY(54, 21);
		cout << "Your mission is to cross the street and deliver the bomb to ";
		GotoXY(54, 22); 
		cout << "our secret agent in the region. Beware of hostile enemies as";
		GotoXY(54, 23); 
		cout << "they ride on vehicles or disguised as innocent animals.";
		GotoXY(54, 24);
		cout << "They will do their best to destroy the bomb so avoid them at ";
		GotoXY(54, 25);
		cout << "all cost!";
		GotoXY(54, 27);
		cout << "Good luck out there agent!";

		break;

	}
	case 3:
	{
		GotoXY(80, 19);
		cout << "DESCRIPTION";
		GotoXY(54, 21);
		cout << "Press Enter to open the setting menu";
		while (_getch() == 13)
		{
			setting();
			TextColor(15);
			GotoXY(80, 19);
			cout << "DESCRIPTION";
			GotoXY(54, 21);
			cout << "Press Enter to open the setting menu";
		}
		break;

	}
	case 4:
	{
		GotoXY(79, 19);
		cout << "ABOUT US!";
		GotoXY(54, 21);
		cout << "UNIVERSITY OF SCIENCE - 20APCS2 - GROUP 2" << endl;
		GotoXY(54, 23);
		cout << "PROJECT ROAD CROSSING GAME";
		GotoXY(54, 25);
		cout << "1. 20125020 - Le Quoc Anh";
		GotoXY(54, 27);
		cout << "2. 20125087 - Huynh Ba Dong Cat";
		GotoXY(54, 29);
		cout << "3. 20125089 - Quang The Cuong";
		GotoXY(54, 31);
		cout << "4. 20125105 - Pham Tan Phat";
		break;

	}
	case 5:
	{
		GotoXY(80, 19);
		cout << "DESCRIPTION";
		GotoXY(54, 21);
		cout << "Press Enter to exit the game" << endl;
		break;

	}
	default:break;
	}
}
void Menu::drawSettings()
{
	GotoXY(55, 21);
	cout << settingList[0];

	GotoXY(55, 23);
	cout << settingList[1];

}

void Menu::setting()
{
	clear();
	GotoXY(80, 19);
	cout << "SETTING";
	GotoXY(54, 34);
	cout << "Press Enter to select";
	drawSettings();
	updateSetting();
}


void Menu::updateSetting()
{
	int i = 0;
	while (1)
	{
		TextColor(14);
		GotoXY(54, y[i] + 5);
		cout << ">" << settingList[i];
		switch (_getch()) {
		case 72:
		{
			if (i > 0)
			{
				GotoXY(54, y[i] + 5);
				TextColor(15);
				cout << " " << settingList[i];
				i--;
			}
			break;
		}
		case 80:
		{
			if (i < 1)
			{
				GotoXY(54, y[i] + 5);
				TextColor(15);
				cout << " " << settingList[i];
				i++;
			}
			break;
		}
		case 13:
		{
			if (i == 1)
			{
				clear();
				return;
			}
			else updateSound();
			break;

		}
		default: break;
		}


	}
}

void Menu::updateSound()
{
	TextColor(15);
	GotoXY(54, 33);
	cout << "Press Enter to turn on/off the sound";
	GotoXY(54, 34);
	cout << "Press Left button to go back to setting menu";
	GotoXY(62, y[0] + 5);
	if (!music->getState())
		TextColor(12);
	else
		TextColor(10);
	cout << "<<" << musicState[music->getState()] << ">> ";
	while (1)
	{
		while (_getch() == 13)
		{
			music->switchState();
			if (music->getState())
				music->play("../GameSound/sound.mp3");
			else
				music->stop("../GameSound/sound.mp3");
			GotoXY(62, y[0] + 5);
			if (!music->getState())
				TextColor(12);
			else
				TextColor(10);
			cout << "<<" << musicState[music->getState()] << ">> ";

		}
		if (_getch() == 75) break;
	}
	GotoXY(62, y[0] + 2);
	cout << "        ";
	TextColor(15);
	GotoXY(54, 33);
	cout << "                                            ";
	GotoXY(54, 34);
	cout << "                                            ";
	GotoXY(54, 34);
	cout << "Press Enter to select";


}