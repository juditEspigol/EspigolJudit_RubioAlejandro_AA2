#pragma once
#include "Player.h"
class Room
{
private:

	Player player;

	struct Door
	{
		int posX;
		int posY;
	};

	int m_width;
	int m_height;
};

