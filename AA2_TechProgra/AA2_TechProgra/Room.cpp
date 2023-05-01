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

char** Room::CreateRoom(const Player& p1)
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
				myRoom[i][j] = printDoor;
			}
			else if (i == 0 && j == m_nextDoor)
			{
				myRoom[i][j] = printDoor;
			}
			else if (i == 0 || i == m_width - 1 || j == 0 || j == m_height - 1)
			{
				myRoom[i][j] = printWall;
			}
			else
			{
				myRoom[i][j] = printEmpty;
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

int Room::GetWidth()
{
	return m_width;
}

int Room::GetHeight()
{
	return m_height;
}

int Room::GetPrevDoor()
{
	return m_prevDoor;
}