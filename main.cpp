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
		GotoXY(16, 5);
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
					GotoXY(54, 18); cout << "Can't load save file. Please enter again";
					Sleep(1000);
					GotoXY(54, 18); cout << "                                                    ";
					continue;
				}
				break;
			}
		}
		else
			break;
		clrscr();
		game.InitDraw();
		srand(time(NULL));
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
					PlaySound("./sound.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
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