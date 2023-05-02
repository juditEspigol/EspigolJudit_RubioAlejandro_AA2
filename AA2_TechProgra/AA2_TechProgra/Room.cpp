#include "Room.h"


// Constructor
Room::Room(TypeOfRoom typeRoom, int numRows, int numColums)
{
	m_typeRoom = typeRoom;
	m_width = numRows;
	m_height = numColums;

	if (m_typeRoom == TypeOfRoom::CLASSROOM)
	{
		m_prevDoor = -1;
		m_nextDoor = numColums / 2;
	}
	else if (m_typeRoom == TypeOfRoom::HALL)
	{
		m_prevDoor = numColums / 2;
		m_nextDoor = numColums / 2;
	}
	else if (m_typeRoom == TypeOfRoom::CAFE)
	{
		m_prevDoor = numColums / 2;
		m_nextDoor = -1;
	}
}

// Methods

char** Room::CreateRoom()
{
	// Create the 2D dynamic array
	char** myRoom = new char* [m_width];
	for (int i = 0; i < m_width; ++i)
	{
		myRoom[i] = new char[m_height];
		for (int j = 0; j < m_height; ++j)
		{
		    if (i == m_height - 1 && j == m_prevDoor)
			{
				myRoom[i][j] = CHAR_DOOR;
			}
			else if (i == 0 && j == m_nextDoor)
			{
				myRoom[i][j] = CHAR_DOOR;
			}
			else if (i == 0 || i == m_width - 1 || j == 0 || j == m_height - 1)
			{
				myRoom[i][j] = CHAR_WALL;
			}
			else
			{
				myRoom[i][j] = CHAR_EMPTY;
			}
		}
	}

	return myRoom;
}

void Room::PrintRoom(char** myRoom)const
{
	for (int y = 0; y < m_width; ++y)
	{
		std::cout << std::endl << " ";
		for (int x = 0; x < m_height; ++x)
		{
			std::cout << myRoom[y][x] << " ";
		}
	}
	std::cout << std::endl;
}

int Room::GetWidth()const
{
	return m_width;
}

int Room::GetHeight()const
{
	return m_height;
}

int Room::GetNextDoor()const
{
	return m_nextDoor;
}

int Room::GetPrevDoor()const
{
	return m_prevDoor;
}