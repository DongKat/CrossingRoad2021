#include "BuildMenu.h"

void Menu::drawDescription(int x)
{

	switch (x)
	{
	case 0:
	{
		GotoXy(51, 14);
		cout << "DESCRIPTION";
		GotoXy(27, 16);
		cout << "Start a new game!";
		break;
	}
	case 1:
	{
		GotoXy(51, 14);
		cout << "DESCRIPTION";
		GotoXy(27, 16);
		cout << "Start with an existed game!";
		break;
	}
	case 2:
	{
		GotoXy(51, 14);
		cout << "DESCRIPTION";
		GotoXy(27, 16);
		cout << "The object of the game, is to cross the street without getting" << endl;
		GotoXy(27, 17);
		cout << "hit by any vehicles or animals";
		break;

	}
	case 3:
	{
		GotoXy(51, 14);
		cout << "DESCRIPTION";
		GotoXy(27, 16);
		cout << "Press Enter to open the setting menu";
		while (_getch() == 13)
		{
			setting();
			TextColor(15);
			GotoXy(51, 14);
			cout << "DESCRIPTION";
			GotoXy(27, 16);
			cout << "Press Enter to open the setting menu";
		}
		break;

	}
	case 4:
	{
		GotoXy(52, 14);
		cout << "ABOUT US!";
		GotoXy(27, 16);
		cout << "UNIVERSITY OF SCIENCE - 20APCS2 - GROUP 2" << endl;
		GotoXy(27, 18);
		cout << "PROJECT ROAD CROSSING GAME";
		GotoXy(27, 20);
		cout << "1. 20125020 - Le Quoc Anh";
		GotoXy(27, 22);
		cout << "2. 20125087 - Huynh Ba Dong Cat";
		GotoXy(27, 24);
		cout << "3. 20125089 - Quang The Cuong";
		GotoXy(27, 26);
		cout << "4. 20125105 - Pham Tan Phat";
		break;

	}
	case 5:
	{
		GotoXy(52, 14);
		cout << "DESCRIPTION";
		GotoXy(27, 16);
		cout << "Press Enter to exit the game" << endl;
		break;

	}
	default:break;
	}
}
void Menu::drawSettings()
{
	GotoXy(28, 16);
	cout << settingList[0];

	GotoXy(28, 18);
	cout << settingList[1];

}

void Menu::setting()
{
	clear();
	GotoXy(53, 14);
	cout << "SETTING";
	GotoXy(27, 29);
	cout << "Press Enter to select";
	drawSettings();
	updateSetting();
}

