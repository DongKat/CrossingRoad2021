#include "BuildConsole.h"

using namespace std;
#define _CRT_SECURE_NO_WARNINGS

void ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();

	//Cố định kích thước
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Resize(int width, int height)
{
	HWND consoleWindow = GetConsoleWindow();
	//Chỉnh kích thước
	RECT r;
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm xóa màn hình.
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	FillConsoleOutputAttribute(hConsoleOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void drawBoard(int xTrai, int yTrai, int xPhai, int yPhai)
{
	//vẽ trước 4 góc
	//góc trên bên trái
	GotoXY(xTrai, yTrai); cout << char(218);
	//m_map[yTrai][xTrai] = 218;
	//vẽ góc trên bên phải
	GotoXY(xPhai, yTrai); cout << char(191);
	//m_map[yTrai][xPhai] = 191;
	//vẽ góc dưới bên trái
	GotoXY(xTrai, yPhai); cout << char(192);
	//m_map[yPhai][xTrai] = 192;
	//vẽ góc dưới bên phải
	//m_map[yPhai][xPhai] = 217;
	GotoXY(xPhai, yPhai); cout << char(217);

	//vẽ chiều ngang bên trên
	for (int i = xTrai + 1; i < xPhai; i++) {
		GotoXY(i, yTrai); cout << char(196);
		//m_map[yTrai][i] = 196;
	}
	//vẽ chiều ngang bên dưới
	for (int i = xTrai + 1; i < xPhai; i++) {
		GotoXY(i, yPhai); cout << char(196);
		//m_map[yPhai][i] = 196;
	}
	//vẽ chiều dọc bên trái
	for (int i = yTrai + 1; i < yPhai; i++) {
		GotoXY(xTrai, i); cout << char(179);
		//m_map[i][xTrai] = 179;
	}
	//vẽ chiều dọc bên phải
	for (int i = yTrai + 1; i < yPhai; i++) {
		GotoXY(xPhai, i); cout << char(179);
		//m_map[i][xPhai] = 179;
	}
}