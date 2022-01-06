#ifndef menu
#define menu
#include <string>
#include "BuildConsole.h"
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <mmsystem.h>
#include <mciapi.h>
#include "Sound.h"

using namespace std;
class Menu {
private:

	vector <string> title =
	{
		"      _____********      ******         **       *******____________________",
		"    /______***   ***    ***  ***       ****      ***  ***__________________/",
		"   /_______***   ***   ***    ***     **  **     ***   ***________________/",
		"  /________********    ***    ***    ********    ***   ***_______________/",
		" /_________***  ***     ***  ***    ***    ***   ***  ***_______________/",
		"/__________***    ***    ******    ***      ***  *******_______________/",
		"                         _____******    ********      ******       *******     *******    ***   ****    ***     ******__________",
		"                        _____***  ***   ***   ***    ***  ***     ***   ***   ***   ***   ***   *****   ***    ***  ***________/",
		"                       _____***         ***   ***   ***    ***     ***         ***        ***   *** **  ***   ***       ______/",
		"                      ______***         ********    ***    ***        ***         ***     ***   ***  ** ***   ***  ******____/",
		"                     ________***  ***   ***  ***     ***  ***     ***   ***   ***   ***   ***   ***   *****    ***   **_____/",
		"                    __________******    ***    ***    ******       *******     *******    ***   ***    ****     ******_____/"
	};
	int levelStart = 0;
	
	string musicState[2] = { "OFF", "ON" };
	string list[6] = { "New game", "Load Game","Instruction", "Settings","About", "Exit" };
	string settingList[2] = { "Music ", "Exit" };
	int y[6] = {  16, 18, 20,22,24,26 };


public:
	Sound* music;
	Menu();
	void drawTitle();
	void drawMenu();
	void drawChoice();
	void updateChoice();
	void drawDescription(int x);
	void drawSettings();
	void setting();
	void updateSetting();
	void updateSound();
	void clear();
};
#endif 
