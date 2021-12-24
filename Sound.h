#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <mciapi.h>
#include <string>
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")

using namespace std;

class SoundGame {
private:
	bool state; //True: play, False: mute
public:
	SoundGame() {
		state = true;
	}
	void turnOn();
	void turnOff();
	void play(string path);
	void stop(string path);
	void pause(string path);
	void resume(string path);
};