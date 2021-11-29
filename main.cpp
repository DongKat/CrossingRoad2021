#include "CrossingRoad.h"

void GotoXY(int x, int y);

int main()
{
	Game game;
	game.updateLevel();
	game.InitDraw();

	while(true)
	{
		game.updateFrame();
		
		game.draw();

		if(game.checkCollision())
		{
			GotoXY(50,15);
			cout << "Game Over" << endl;
			break;
		}
		
		Sleep(1);
	}


	system("pause");
	return 0;
}