#ifndef sound
#define sound
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include <iostream>
#pragma comment(lib, "Winmm.lib")

using namespace std;

class Sound
{
private:
	bool turn;
public:
	Sound() : turn(true) {};
	bool getState() { return turn; }
	void switchState() { turn = !turn; }
	void play(string path);
	void stop(string path);
	void pause(string path);
	void resume(string path);
};
#endif
