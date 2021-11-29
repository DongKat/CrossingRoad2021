#include "CrossingRoad.h"

int main()
{
	Game game;
	game.updateLevel();
	
	while(true)
	{
		game.updateFrame();
		game.draw();
		Sleep(400);
		system("cls");

	}


	system("pause");
	return 0;
}