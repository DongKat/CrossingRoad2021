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
	PlaySound(path, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void SoundGame::stop(string path)
{
	string dir = "close " + path;
	PlaySound(NULL, NULL, NULL);
}

//void SoundGame::pause(string path)
//{
//	string dir = "pause " + path;
//	mciSendString(dir.c_str(), NULL, 0, NULL);
//}
//
//void SoundGame::resume(string path)
//{
//	string dir = "resume " + path;
//	mciSendString(dir.c_str(), NULL, 0, NULL);
//}
