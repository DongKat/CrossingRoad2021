#include "DrawMenu.h"

Menu::Menu()
{
	m_width = 20;
	m_height = 50;
	m_x = 50;
}

void Menu::drawChoice()
{
	clrscr();
	ShowConsoleCursor(1);
	
	GotoXy(m_x - m_title.length() / 2, 0);
	cout << m_title;

	GotoXy(m_x-4, 2);
	cout << "MAIN MENU"; TextColor(15);
	
	for (int i = 0; i < 4; ++i) 
	{
		GotoXy(m_x-m_list[i].length()/2, m_y[i]);
		cout << m_list[i];
	}
}

int Menu::updateChoice()
{
	int i = 0;
	while (1) 
	{
		GotoXy(m_x - m_list[i].length() / 2, m_y[i]);
		TextColor(14);
		cout << m_list[i];
		switch (_getch()) {
		case 72: {
			if (i > 0)
			{
				GotoXy(m_x - m_list[i].length()/2, m_y[i]);
				TextColor(15);
				cout << m_list[i];
				i--;
			}
			break;
		}
		case 80: {
			if (i < 3) {
				GotoXy(m_x - m_list[i].length()/2, m_y[i]);
				TextColor(15);
				cout << m_list[i];
				i++;
			}
			break;
		}
		case 13: {
			TextColor(15);
			return i;
		}
		default: break;
		}
	}
}

void Menu::drawSettings()
{
	clrscr();
	ShowConsoleCursor(1);

	GotoXy(m_x - m_title.length() / 2, 0);
	cout << m_title;
	
	GotoXy(m_x - 4, 2);
	cout << "SETTING"; TextColor(15);

	GotoXy(m_x-m_settingList[0].length()/2, m_y[0]);
	cout<< m_settingList[0]<< musicState[music];

	GotoXy(m_x - m_settingList[1].length() / 2, m_y[1]);
	cout<< m_settingList[1];

}

void Menu::setting(SoundGame sound)
{
	drawSettings();
	updateSetting(sound);
}

void Menu::updateSetting(SoundGame sound)
{
	int i = 0;
	while (1)
	{
		TextColor(14);
		GotoXy(m_x - m_settingList[i].length() / 2, m_y[i]);
		cout<< m_settingList[i];
		switch (_getch()) {
		case 72: 
		{
			if (i > 0)
			{
				GotoXy(m_x - m_settingList[i].length() / 2, m_y[i]);
				TextColor(15);
				cout << m_settingList[i];
				i--;
			}
			break;
		}
		case 80: 
		{
			if (i < 1) 
			{
				GotoXy(m_x - m_settingList[i].length() / 2, m_y[i]);
				TextColor(15);
				cout << m_settingList[i];
				i++;
			}
			break;
		}
		case 13:
				{
					GotoXy(m_x - m_settingList[i].length() / 2, m_y[i]);
					TextColor(14);
					if (i == 0)
					{
						cout << m_settingList[i] << musicState[!music] << " ";
						music = !music;
						if (music)
						   sound.play("../Sound/opening.mp3");
						else
						   sound.stop("../Sound/opening.mp3");
					}
					else
						return;
					
				}
		default: break;
		}
		

	}
}