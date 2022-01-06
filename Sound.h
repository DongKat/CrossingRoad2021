#ifndef sound
#define sound
#include <Windows.h>
#include <string>
#pragma comment(lib, "Winmm.lib")

using namespace std;

class Sound
{
private:
	bool turn; 
public:
	Sound() 
	{
		turn = true;
	}
	bool getState() { return turn; }
	void switchState() { turn = !turn; }
	void play(string file);
	void stop(string file);
	void pause(string file);
	void resume(string file);
};
#endif