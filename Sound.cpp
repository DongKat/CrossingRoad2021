#include "Sound.h"

void Sound::play(string path)
{
	string dir = "play " + path + " repeat";
	mciSendString(dir.c_str(), NULL, 0, NULL);
}

void Sound::stop(string path)
{
	string dir = "close " + path;
	mciSendString(dir.c_str(), NULL, 0, NULL);
}

void Sound::pause(string path)
{
	string dir = "pause " + path;
	mciSendString(dir.c_str(), NULL, 0, NULL);
}

void Sound::resume(string path)
{
	string dir = "resume " + path;
	mciSendString(dir.c_str(), NULL, 0, NULL);
}