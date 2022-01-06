#include "BuildMenu.h"

Menu::Menu()
{
	
}
void Menu::drawMenu()
{
	clrscr();
	ShowConsoleCursor(1);
	drawTitle();
	drawBoard(10, 12, 90, 30);
	drawBoard(25, 12, 90, 30);
}
void Menu::drawTitle()
{
	TextColor(9);
	for (int i = 0; i < 6; i++) 
	{
		cout << title[i]<<endl;
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

	GotoXy(14, 14);
	cout << "MAIN MENU"; TextColor(15);

	for (int i = 0; i < 6; ++i)
	{
		GotoXy(13, y[i]);
		cout << list[i];
	}
}
void Menu::clear()
{
	for (int i = 14; i < 30; ++i)
	{
		GotoXy(26, i);
		cout << "                                                                ";
	}
}
void Menu::updateChoice()
{
	int i = 0;
	char x;
	while (1)
	{
		clear();
		GotoXy(12, y[i]);
		TextColor(14);
		cout << ">"<<list[i];
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
				GotoXy(12, y[i]);
				TextColor(15);
				cout <<" "<< list[i];
				i--;
			}
			break;
		}
		case 80: {
			if (i < 5) {
				GotoXy(12, y[i]);
				TextColor(15);
				cout <<" "<< list[i];
				i++;
			}
			break;
		}
		case 13: {if (i == 5) return; break; }
		default: break;
		}
	}
}
