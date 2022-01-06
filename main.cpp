#include "CrossingRoad.h"

void GotoXY(int x, int y);

int main()
{
	Sound music;
	music.play("sound.wav");
	Game game;
	Menu memu(&music);
	Resize(1280, 760);
	FixConsoleWindow();
	memu.drawTitle();
	memu.drawMenu();
	memu.drawChoice();
	int tmp = memu.updateChoice();
	if (tmp == 0)
	{
		//new game

	}
	else if (tmp == 1)
	{
		//load game
		string temp;
		temp = memu.LoadGame();
		game.loadGame(temp);
	}
	clrscr();
	game.InitDraw();
	while (true)
	{
		game.draw();
		game.updateFrame();

		if (game.checkCollision())
		{
			// display Game over screen
			game.gameOverAnimation();
			break;
		}

		Sleep(10);
	}


	system("pause");
	return 0;
}