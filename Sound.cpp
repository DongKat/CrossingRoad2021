#include "Sound.h"

void Sound::play(string path)
{
	PlaySound(TEXT(path.c_str()), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void Sound::stop(string path)
{
	PlaySound(NULL, NULL, NULL);
}