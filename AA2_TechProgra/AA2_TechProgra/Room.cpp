#include "Room.h"

// CONSTRUCTOR
Room::Room(TypeOfRoom typeRoom, int width, int heigth)
{
	m_typeRoom = typeRoom;
	m_width = width;
	m_height = heigth;

	if (m_typeRoom == TypeOfRoom::CLASSROOM)
	{
		m_prevDoor = -1;
		m_nextDoor = width / 2;
	}
	else if (m_typeRoom == TypeOfRoom::HALL)
	{
		m_prevDoor = width / 2;
		m_nextDoor = width / 2;
	}
	else if (m_typeRoom == TypeOfRoom::CAFE)
	{
		m_prevDoor = width / 2;
		m_nextDoor = -1;
	}

	for (int i = 0; i < 4; i++)
	{
		RewardObject pot(width, heigth);
		m_pots.push_back(pot);
	}
}

// GETTERS
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

// METHODS
char** Room::CreateRoom(const int& width, const int& height)
{
	// Create the 2D dynamic array
	char** myRoom = new char* [m_height];
	for (int y = 0; y < m_height; ++y)
	{
		myRoom[y] = new char[m_width];
		for (int x = 0; x < m_width; ++x)
		{
		    if (y == m_height - 1 && x == m_prevDoor)
			{
				myRoom[y][x] = CHAR_DOOR;
			}
			else if (y == 0 && x == m_nextDoor)
			{
				myRoom[y][x] = CHAR_DOOR;
			}
			else if (y == 0 || y == m_height - 1 || x == 0 || x == m_width - 1)
			{
				myRoom[y][x] = CHAR_WALL;
			}
			else
			{
				myRoom[y][x] = CHAR_EMPTY;
			}
			for (int i = 0; i < m_pots.size(); i++)
			{
				////Mirar ESTOOOOOOOOOOOOOOOO
				//while (myRoom[m_pots[i].GetPosY()][m_pots[i].GetPosX()] != CHAR_EMPTY)
				//{
				//	m_pots[i].ResetPos(width, height);
				//}
				if (y == m_pots[i].GetPosY() && x == m_pots[i].GetPosX())
					myRoom[y][x] = CHAR_POT;
			}
		}
	}

	return myRoom;
}

void Room::PrintRoom(char** myRoom)const
{
	printTypeOfRoom(m_typeRoom); 
	for (int y = 0; y < m_height; ++y)
	{
		std::cout << std::endl; 
		for (int x = 0; x < m_width; ++x)
		{
			std::cout << " ";
			if (myRoom[y][x] == CHAR_DOOR)
				std::cout << YELLOW_TEXT << myRoom[y][x];
			else if (myRoom[y][x] == CHAR_POT)
				std::cout << RED_TEXT << myRoom[y][x];
			else if (myRoom[y][x] == CHAR_GEM_GREEN)
				std::cout << GREEN_TEXT << myRoom[y][x];
			else if (myRoom[y][x] == CHAR_GEM_BLUE)
				std::cout << GRAY_TEXT << myRoom[y][x];
			else if (myRoom[y][x] == CHAR_GEM_RED)
				std::cout << RED_TEXT << myRoom[y][x];
			else if (myRoom[y][x] != CHAR_WALL && myRoom[y][x] != CHAR_EMPTY)
				std::cout << GREEN_TEXT << myRoom[y][x];
			else
				std::cout << GRAY_TEXT << myRoom[y][x];
			
		}
		std::cout << " "; 
	}
	std::cout << std::endl;
}

// FUNCTIONS 
void deleteDynamicArray(char** myRoom, std::list<Room>::iterator it)
{
	for (int i = 0; i < it->GetWidth(); i++)
	{
		delete[] myRoom[i];
	}
	delete[] myRoom;

	myRoom = nullptr;
}

void printTypeOfRoom(TypeOfRoom typeRoom)
{
	switch (typeRoom)
	{
	case TypeOfRoom::CLASSROOM:
		std::cout << " -- CLASSROOM -- " << std::endl;
		break;
	case TypeOfRoom::HALL:
		std::cout << " -- HALL -- " << std::endl;
		break;
	case TypeOfRoom::CAFE:
		std::cout << " -- CAFE -- " << std::endl;
		break;
	case TypeOfRoom::COUNT:
		std::cout << "  " << std::endl;
		break;
	default:
		break;
	}
}