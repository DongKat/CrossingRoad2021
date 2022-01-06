#include "BuildMenu.h"
class PlayGame
{
public:
	Menu gameMenu;
	Sound gameSound;
};
int main()
{
	FixConsoleWindow();
	PlayGame player;
	player.gameMenu.drawMenu();
	(player.gameMenu).music = &player.gameSound;
	(player.gameMenu).music->play("../GameSound/sound.mp3");
	while (1)
	{
		player.gameMenu.drawChoice();
		player.gameMenu.updateChoice();
	}

	return 0;
}