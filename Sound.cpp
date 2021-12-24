#include "Sound.h"

void SoundGame::turnOn()
{
	state = true;
}

void SoundGame::turnOff()
{
	state = false;
}

void SoundGame::play(string path)
{
	string dir = "play " + path + " repeat";
	mciSendString(dir.c_str(), NULL, 0, NULL);
}

void SoundGame::stop(string path)
{
	string dir = "close " + path;
	mciSendString(dir.c_str(), NULL, 0, NULL);
}

void SoundGame::pause(string path)
{
	string dir = "pause " + path;
	mciSendString(dir.c_str(), NULL, 0, NULL);
}

void SoundGame::resume(string path)
{
	string dir = "resume " + path;
	mciSendString(dir.c_str(), NULL, 0, NULL);
}
