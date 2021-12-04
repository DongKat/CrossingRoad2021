#include "CrossingRoad.h"

void GotoXY(int x, int y);

int main()
{
	/*Player p;
	p.draw();
	cout << "a";*/
	Game game;
	game.updateLevel();
	game.InitDraw();
	while(true)
	{
		
		
		game.draw();
		game.updateFrame();
		if(game.checkCollision())
		{
			GotoXY(100,3);
			cout << "Collided: True ";
		}
		else
		{
			GotoXY(100,3);
			cout << "Collided: False";
		}
		Sleep(1);
	}

	
	system("pause");
	return 0;
}