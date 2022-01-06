#include "Sound.h"

void Sound::play(string path)
{
	string dir = "play " + path + " repeat";
	PlaySound("./sound.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void Sound::stop(string path)
{
	string dir = "close " + path;
	PlaySound(NULL, NULL, NULL);
}

