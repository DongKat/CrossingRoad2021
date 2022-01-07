#include "BuildMenu.h"

Menu::Menu(Sound* s)
{
	music = s;
}
void Menu::drawMenu()
{
	clrscr();
	drawTitle();
	drawBoard(10, 12, 91, 30);
	drawBoard(25, 12, 91, 30);
	drawBoard(10, 31, 45, 33);
	TextColor(3);
	GotoXY(12, 32); cout << "USE ARROWS TO NAVIGATE THE MENU";
	TextColor(15);
}
void Menu::drawTitle()
{
	TextColor(9);
	for (int i = 0; i < 6; i++)
	{
		cout << title[i] << endl;
	}
	TextColor(12);
	for (int i = 6; i < 12; i++)
	{
		cout << title[i] << endl;
	}
	TextColor(15);
}

void Menu::drawChoice()
{

	GotoXY(14, 14);
	cout << "MAIN MENU"; TextColor(15);

	for (int i = 0; i < 6; ++i)
	{
		GotoXY(13, y[i]);
		cout << list[i];
	}
}
void Menu::clear()
{
	for (int i = 14; i < 30; ++i)
	{
		GotoXY(26, i);
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
		GotoXY(12, y[i]);
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
				GotoXY(12, y[i]);
				TextColor(15);
				cout << " " << list[i];
				i--;
			}
			break;
		}
		case 80: {
			if (i < 5) {
				GotoXY(12, y[i]);
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
	GotoXY(27, 16); cout << "                                                   ";
	GotoXY(27, 16);	cout << "Enter your save file name:";
	GotoXY(27, 18); cout << "                                                   ";
	ShowConsoleCursor(true);
	GotoXY(27, 18); getline(cin, temp);
	ShowConsoleCursor(false);

	return temp;
}

void Menu::drawDescription(int x)
{

	switch (x)
	{
	case 0:
	{
		GotoXY(51, 14);
		cout << "DESCRIPTION";
		GotoXY(27, 16);
		cout << "Start a new game!";
		break;
	}
	case 1:
	{
		GotoXY(51, 14);
		cout << "DESCRIPTION";
		GotoXY(27, 16);
		cout << "Start with an existed game!";
		break;
	}
	case 2:
	{
		GotoXY(51, 14);
		cout << "DESCRIPTION";
		GotoXY(27, 16);
		cout << "The objective of the game is to cross the street without getting" << endl;
		GotoXY(27, 17);
		cout << "hit by vehicles or animals. Good luck!";
		break;

	}
	case 3:
	{
		GotoXY(51, 14);
		cout << "DESCRIPTION";
		GotoXY(27, 16);
		cout << "Press Enter to open the setting menu";
		while (_getch() == 13)
		{
			setting();
			TextColor(15);
			GotoXY(51, 14);
			cout << "DESCRIPTION";
			GotoXY(27, 16);
			cout << "Press Enter to open the setting menu";
		}
		break;

	}
	case 4:
	{
		GotoXY(52, 14);
		cout << "ABOUT US!";
		GotoXY(27, 16);
		cout << "UNIVERSITY OF SCIENCE - 20APCS2 - GROUP 2" << endl;
		GotoXY(27, 18);
		cout << "PROJECT ROAD CROSSING GAME";
		GotoXY(27, 20);
		cout << "1. 20125020 - Le Quoc Anh";
		GotoXY(27, 22);
		cout << "2. 20125087 - Huynh Ba Dong Cat";
		GotoXY(27, 24);
		cout << "3. 20125089 - Quang The Cuong";
		GotoXY(27, 26);
		cout << "4. 20125105 - Pham Tan Phat";
		break;

	}
	case 5:
	{
		GotoXY(52, 14);
		cout << "DESCRIPTION";
		GotoXY(27, 16);
		cout << "Press Enter to exit the game" << endl;
		break;

	}
	default:break;
	}
}
void Menu::drawSettings()
{
	GotoXY(28, 16);
	cout << settingList[0];

	GotoXY(28, 18);
	cout << settingList[1];

}

void Menu::setting()
{
	clear();
	GotoXY(53, 14);
	cout << "SETTING";
	GotoXY(27, 29);
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
		GotoXY(27, y[i]);
		cout << ">" << settingList[i];
		switch (_getch()) {
		case 72:
		{
			if (i > 0)
			{
				GotoXY(27, y[i]);
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
				GotoXY(27, y[i]);
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
	GotoXY(27, 28);
	cout << "Press Enter to turn on/off the sound";
	GotoXY(27, 29);
	cout << "Press Left button to go back to setting menu";
	GotoXY(35, y[0]);
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
			GotoXY(35, y[0]);
			if (!music->getState())
				TextColor(12);
			else
				TextColor(10);
			cout << "<<" << musicState[music->getState()] << ">> ";

		}
		if (_getch() == 75) break;
	}
	GotoXY(35, y[0]);
	cout << "        ";
	TextColor(15);
	GotoXY(27, 28);
	cout << "                                            ";
	GotoXY(27, 29);
	cout << "                                            ";
	GotoXY(27, 29);
	cout << "Press Enter to select";


}