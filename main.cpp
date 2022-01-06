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
	ShowConsoleCursor(false);
	while (true)
	{
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
			while (true)
			{
				try
				{
					string temp;
					temp = memu.LoadGame();
					game.loadGame(temp);
				}
				catch (runtime_error e)
				{
					GotoXY(27, 18); cout << "Can't load save file. Please enter again";
					GotoXY(27, 18); cout << "                                                    ";
					continue;
				}
				break;
			}
		}
		else
			break;
		clrscr();
		game.InitDraw();
		try
		{
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
		}
		catch (const char* e)
		{
		}
		game.resetGame();
	}

	return 0;
}