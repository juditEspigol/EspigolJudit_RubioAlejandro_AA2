#include "Room.h"

Room::Room()
{
	m_width = 8;
	m_height = 5;

	myRoom = new Cell* [m_width];

	for (int i = 0; i < m_width; i++)
	{
		myRoom[i] = new Cell[m_height];
	}

	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			if (myRoom[i][j].player.GetPosX() == i && myRoom[i][j].player.GetPosY() == j)
			{
				
			}
		}
	}
}

Room::~Room()
{
	for (int i = 0; i < m_width; i++)
	{
		delete[] myRoom[i];
	}

	delete[] myRoom;
	myRoom = nullptr;
}


/*
// Constructor
Room::Room(TypeRoom typeRoom, int numRows, int numColums)
{
	m_typeRoom = typeRoom;
	m_numRows = numRows;
	m_numColums = numColums;
	m_prevDoor = numColums / 2;
	m_nextDoor = numColums / 2;
}

// Methods
char** Room::InicializeRoom(const Player& p1)
{
	// Create the 2D dynamic array
	char** myRoom = new char* [m_numRows];
	for (int y = 0; y < m_numRows; ++y)
	{
		myRoom[y] = new char[m_numColums];
		for (int x = 0; x < m_numColums; ++x)
		{
			if (y == p1.m_posY && x == p1.m_posX)
			{
				myRoom[y][x] = '^';
			}
			else if (y == 0 && x == m_nextDoor)
			{
				myRoom[y][x] = CHAR_DOOR;
			}
			else if (y == 0 || y == m_numRows - 1 || x == 0 || x == m_numColums - 1)
			{
				myRoom[y][x] = CHAR_WALL;
			}
			else
			{
				myRoom[y][x] = CHAR_EMPTY;
			}
		}
	}
	return myRoom;
}

void Room::PrintRoom(char** myRoom) const
{
	for (int y = 0; y < m_numRows; ++y)
	{
		std::cout << std::endl << " ";
		for (int x = 0; x < m_numColums; ++x)
		{
			std::cout << myRoom[y][x] << " ";
		}
	}
	std::cout << std::endl;
}

*/
