#include "Sound.h"

void Sound::play(string file)
{
	string dir = "play " + file + " repeat";
	mciSendString((LPCWSTR)dir.c_str(), NULL, 0, NULL);
}

void Sound::stop(string file)
{
	string dir = "close " + file;
	mciSendString((LPCWSTR)dir.c_str(), NULL, 0, NULL);
}

void Sound::pause(string file)
{
	string dir = "pause " + file;
	mciSendString((LPCWSTR)dir.c_str(), NULL, 0, NULL);
}

void Sound::resume(string file)
{
	string dir = "resume " + file;
	mciSendString((LPCWSTR)dir.c_str(), NULL, 0, NULL);
}
