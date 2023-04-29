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

