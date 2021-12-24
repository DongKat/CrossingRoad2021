#pragma once
#include <string>
#include "BuildConsole.h"
#include "Sound.h"
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <mmsystem.h>
#include <mciapi.h>

using namespace std;
class Menu {
private:
	
	string m_title = "Welcome to Road Crossing Game";
    int m_width, m_height;
	int levelStart = 0, music = 1;
	string musicState[2] = {"OFF", "ON"};
	string m_list[4] = {"New game", "Load Game", "Settings", "Exit"};
	string m_settingList[2] = { "Music: ", "Exit"};
	int m_x;
	int m_y[4] = { 4, 6, 8, 10};


public:
	Menu();
	void drawChoice();
	int updateChoice();
	void drawSettings();
	void setting(SoundGame sound);
	void updateSetting(SoundGame sound);
};