#ifndef console
#define console
#include <Windows.h>
#include <iostream>

using namespace std;

#define CONSOLE_WIDTH 200
#define	CONSOLE_HEIGHT 30

void ShowConsoleCursor(bool showFlag);
void Resize(int, int);
void FixConsoleWindow();
void TextColor(int x);
void GotoXY(int x, int y);
void clrscr();
void drawBoard(int, int, int, int);
#endif