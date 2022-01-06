#ifndef console
#define console
#include <Windows.h>
#include <iostream>

using namespace std;

#define CONSOLE_WIDTH 200
#define	CONSOLE_HEIGHT 30

/*const int BOARD_STARTX = 0;
const int BOARD_STARTY = 2;
const int BOARD_ENDX = 90;
const int BOARD_ENDY = 28;
const int MENU_WIDTH = 15;
const int MENU_HEIGHT = 5;*/

void ShowConsoleCursor(bool showFlag);
void Resize(int, int);
void FixConsoleWindow();
void TextColor(int x);
void GotoXy(int x, int y);
void clrscr();
void drawBoard(int, int, int, int);
#endif