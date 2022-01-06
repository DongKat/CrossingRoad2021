#include "BuildMenu.h"

void Menu::updateSetting()
{
	int i = 0;
	while (1)
	{
		TextColor(14);
		GotoXy(27, y[i]);
		cout << ">" << settingList[i];
		switch (_getch()) {
		case 72:
		{
			if (i > 0)
			{
				GotoXy(27, y[i]);
				TextColor(15);
				cout << " " << settingList[i];
				i--;
			}
			break;
		}
		case 80:
		{
			if (i < 1)
			{
				GotoXy(27, y[i]);
				TextColor(15);
				cout << " " << settingList[i];
				i++;
			}
			break;
		}
		case 13:
		{
			if (i == 1)
			{
				clear();
				return;
			}
			else updateSound();
			break;

		}
		default: break;
		}


	}
}

void Menu::updateSound()
{
	TextColor(15);
	GotoXy(27, 28);
	cout << "Press Enter to turn on/off the sound";
	GotoXy(27, 29);
	cout << "Press Left button to go back to setting menu";
	GotoXy(35, y[0]);
	cout << "<<" << musicState[music->getState()] << ">> ";
	while (1)
	{
		while (_getch() == 13)
		{
			music->switchState();
			if (!music->getState())
				music->resume("../GameSound/sound.mp3");
			else
				music->pause("../GameSound/sound.mp3");
			GotoXy(35, y[0]);
			cout << "<<" << musicState[music->getState()] << ">> ";

		} 
		if (_getch() == 75) break;
	}
	GotoXy(35, y[0]);
	cout << "        ";

}