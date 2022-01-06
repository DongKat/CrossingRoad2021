#include "Sound.h"

void Sound::play(string path)
{
	string dir = "play " + path + " repeat";
	PlaySound((LPCWSTR)path.c_str(), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void Sound::stop(string path)
{
	PlaySound(NULL, NULL, NULL);
}