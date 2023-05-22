#include "Room.h"

// CONSTRUCTOR
Room::Room(TypeOfRoom typeRoom, int width, int height)
{
	m_typeRoom = typeRoom;
	m_width = width;
	m_height = height;

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
			else if (myRoom[y][x] == CHAR_WILDPIG)
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
		std::cout << std::endl  << " -- CLASSROOM -- " << std::endl;
		break;
	case TypeOfRoom::HALL:
		std::cout << std::endl  << " -- HALL -- " << std::endl;
		break;
	case TypeOfRoom::CAFE:
		std::cout << std::endl  << " -- CAFE -- " << std::endl;
		break;
	case TypeOfRoom::COUNT:
		std::cout << "  " << std::endl;
		break;
	default:
		break;
	}
}

void Room::CreatePots(char** myRoom, const int& numPots) 
{
	while (m_pots.size() < numPots)
	{
		RewardObject pot(m_width, m_height);

		if (myRoom[pot.GetPosY()][pot.GetPosX()] == CHAR_EMPTY)
		{
			m_pots.push_back(pot); 
			myRoom[pot.GetPosY()][pot.GetPosX()] = CHAR_POT; 
		}
	}
}


void Room::CreateEnemys(char** myRoom, const int& numPigs)
{
	while (m_wildPigs.size() < numPigs)
	{
		WildPig enemy(m_width, m_height);

		if (myRoom[enemy.GetPosY()][enemy.GetPosX()] == CHAR_EMPTY)
		{
			m_wildPigs.push_back(enemy);
			myRoom[enemy.GetPosY()][enemy.GetPosX()] = CHAR_WILDPIG;
		}
	}
}