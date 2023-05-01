#pragma once
#include "Player.h"


const char printDoor = 'D';
const char printPlayer = 'P';
const char printWall = 'X';
const char printEmpty = ' ';

enum class TypeOfRoom {
	CLASSROOM,
	HALL,
	CAFE,
	COUNT
};

class Room
{
private:

	struct Cell
	{

		struct Door
		{
			int posX;
		};

		Player player;
	};

	TypeOfRoom m_typeRoom;

	int m_prevDoor;
	int m_nextDoor;

	int m_width;
	int m_height;

public:	

	Room(TypeOfRoom typeofRoom, int numRows, int numColums);

	char** CreateRoom(const Player& p1);

	void PrintRoom(char** myRoom) const;

	void SetPlayer(char** myRoom);

	int GetWidth();

	int GetHeight();

	int GetPrevDoor();
};

