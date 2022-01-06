#include "CrossingRoad.h"

void GotoXY(int x, int y);

int main()
{
	/*Player p;
	p.draw();
	cout << "a";*/
	Game game;
	// game.updateLevel();
	Resize(1280, 760);
	FixConsoleWindow();
	game.InitDraw();
	while (true)
	{


		game.draw();
		game.updateFrame();

		if (game.checkCollision())
		{
			// display Game over screen
			break;
		}

		Sleep(10);
	}


	system("pause");
	return 0;
}