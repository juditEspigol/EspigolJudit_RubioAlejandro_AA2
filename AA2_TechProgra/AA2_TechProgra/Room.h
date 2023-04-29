#pragma once
#include "Player.h"

const char printDoor = 'D';
const char printPlayer = 'P';
const char printWall = 'X';
const char printEmpty = ' ';

class Room
{
private:

	struct Cell
	{

		struct Door
		{
			int posX;
			int posY;
		};

		Player player;
		Door door;


	};

	int m_width;
	int m_height;

	Cell** myRoom;

public:	

	Room();

	~Room();
};

