#include "Room.h"

// CONSTRUCTOR

Room::Room(TypeOfRoom typeRoom, int width, int height, int enemys, int pots)
{
	m_typeRoom = typeRoom;
	m_width = width;
	m_height = height;
	m_numWildPigs = enemys;
	m_numPots = pots; 
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

TypeOfRoom Room::GetTypeOfRoom()const
{
	return m_typeRoom;
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
			else if (myRoom[y][x] == CHAR_GANON)
				std::cout << GREEN_TEXT << myRoom[y][x];
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
void Room::DeleteDynamicArray(char** myRoom, std::list<Room>::iterator it)
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

void Room::CreatePots(char** myRoom)
{
	m_pots.clear();
	while (m_pots.size() < m_numPots)
	{
		RewardObject pot(m_width, m_height);

		if (myRoom[pot.GetPosY()][pot.GetPosX()] == CHAR_EMPTY)
		{
			m_pots.push_back(pot);
			myRoom[pot.GetPosY()][pot.GetPosX()] = CHAR_POT;
		}
	}
}


void Room::CreateEnemys(char** myRoom)
{
	m_wildPigs.clear();
	while (m_wildPigs.size() < m_numWildPigs)
	{
		WildPig enemy(m_width, m_height);

		if (myRoom[enemy.GetPosY()][enemy.GetPosX()] == CHAR_EMPTY)
		{
			m_wildPigs.push_back(enemy);
			myRoom[enemy.GetPosY()][enemy.GetPosX()] = CHAR_WILDPIG;
		}
	}
}

void Room::CreateGanon(char** myRoom)
{
	bool ganonCreated = false;
	while (ganonCreated == false)
	{
		Ganon ganon(m_width, m_height);

		if (myRoom[ganon.GetPosY()][ganon.GetPosX()] == CHAR_EMPTY)
		{
			m_ganon.push_back(ganon);
			myRoom[ganon.GetPosY()][ganon.GetPosX()] = CHAR_GANON;
			ganonCreated = true;
		}
	}
}

void Room::MoveEnemys(char** myRoom, Player& player)
{
	for (int i = 0; i < m_wildPigs.size(); ++i)
	{
		switch (m_wildPigs[i].GetDirection())
		{
		case DirectionEnemys::UP:
			if (EnemiesCheckMovement(myRoom, m_wildPigs[i], m_wildPigs[i].GetDirection()))
			{
				myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_EMPTY;
				m_wildPigs[i].SetPosition(m_wildPigs[i].GetPosX(), m_wildPigs[i].GetPosY() - 1);
				myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_WILDPIG;
			}
			else
			{
				if (myRoom[m_wildPigs[i].GetPosY() - 1][m_wildPigs[i].GetPosX()]
					== myRoom[player.GetPosY()][player.GetPosX()])
				{
					myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_EMPTY;
					m_wildPigs[i].SetAlive(false);
					m_wildPigs.erase(m_wildPigs.begin() + i);
					player.SubstractHealth(1);
				}
				else
					m_wildPigs[i].SetDirection(DirectionEnemys::DOWN);
			}
			break;
		case DirectionEnemys::DOWN:
			if (EnemiesCheckMovement(myRoom, m_wildPigs[i], m_wildPigs[i].GetDirection()))
			{
				myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_EMPTY;
				m_wildPigs[i].SetPosition(m_wildPigs[i].GetPosX(), m_wildPigs[i].GetPosY() + 1);
				myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_WILDPIG;
			}
			else
			{
				if (myRoom[m_wildPigs[i].GetPosY() + 1][m_wildPigs[i].GetPosX()]
					== myRoom[player.GetPosY()][player.GetPosX()])
				{
					myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_EMPTY;
					m_wildPigs[i].SetAlive(false);
					m_wildPigs.erase(m_wildPigs.begin() + i);
					player.SubstractHealth(1);
				}
				else
					m_wildPigs[i].SetDirection(DirectionEnemys::UP);
			}
			break;
		case DirectionEnemys::LEFT:
			if (EnemiesCheckMovement(myRoom, m_wildPigs[i], m_wildPigs[i].GetDirection()))
			{
				myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_EMPTY;
				m_wildPigs[i].SetPosition(m_wildPigs[i].GetPosX() - 1, m_wildPigs[i].GetPosY());
				myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_WILDPIG;
			}
			else
			{
				if (myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX() - 1]
					== myRoom[player.GetPosY()][player.GetPosX()])
				{
					myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_EMPTY;
					m_wildPigs[i].SetAlive(false);
					m_wildPigs.erase(m_wildPigs.begin() + i);
					player.SubstractHealth(1);
				}
				else
					m_wildPigs[i].SetDirection(DirectionEnemys::RIGHT);
			}
			break;
		case DirectionEnemys::RIGHT:
			if (EnemiesCheckMovement(myRoom, m_wildPigs[i], m_wildPigs[i].GetDirection()))
			{
				myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_EMPTY;
				m_wildPigs[i].SetPosition(m_wildPigs[i].GetPosX() + 1, m_wildPigs[i].GetPosY());
				myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_WILDPIG;
			}
			else
			{
				if (myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX() + 1]
					== myRoom[player.GetPosY()][player.GetPosX()])
				{
					myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()] = CHAR_EMPTY;
					m_wildPigs[i].SetAlive(false);
					m_wildPigs.erase(m_wildPigs.begin() + i);
					player.SubstractHealth(1);
				}
				else
					m_wildPigs[i].SetDirection(DirectionEnemys::LEFT);
			}
			break;
		default:
			break;
		}
	}
}

void Room::MoveGanon(char** myRoom, Player& player)
{
	m_ganon[0].RandomDirection();
	switch (m_ganon[0].GetDirection())
	{
	case DirectionEnemys::UP:
		if (GanonCheckMovement(myRoom, m_ganon[0].GetDirection()))
		{
			myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_EMPTY;
			m_ganon[0].SetPosition(m_ganon[0].GetPosX(), m_ganon[0].GetPosY() - 1);
			myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_GANON;
		}
		else
		{
			if (myRoom[m_ganon[0].GetPosY() - 1][m_ganon[0].GetPosX()]
				== myRoom[player.GetPosY()][player.GetPosX()])
			{
				myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_EMPTY;
				m_ganon[0].SubstractHealth(1);
				player.SubstractHealth(m_ganon[0].GetDamage());
			}
			
			break;
		}
	case DirectionEnemys::DOWN:
		if (GanonCheckMovement(myRoom, m_ganon[0].GetDirection()))
		{
			myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_EMPTY;
			m_ganon[0].SetPosition(m_ganon[0].GetPosX(), m_ganon[0].GetPosY() + 1);
			myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_GANON;
		}
		else
		{
			if (myRoom[m_ganon[0].GetPosY() + 1][m_ganon[0].GetPosX()]
				== myRoom[player.GetPosY()][player.GetPosX()])
			{
				myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_EMPTY;
				m_ganon[0].SubstractHealth(1);
				player.SubstractHealth(m_ganon[0].GetDamage());
			}
			
			break;
		}
	case DirectionEnemys::LEFT:
		if (GanonCheckMovement(myRoom, m_ganon[0].GetDirection()))
		{
			myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_EMPTY;
			m_ganon[0].SetPosition(m_ganon[0].GetPosX() - 1, m_ganon[0].GetPosY());
			myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_GANON;
		}
		else
		{
			if (myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX() - 1]
				== myRoom[player.GetPosY()][player.GetPosX()])
			{
				myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_EMPTY;
				m_ganon[0].SubstractHealth(1);
				player.SubstractHealth(m_ganon[0].GetDamage());
			}
			
			break;
		}
	case DirectionEnemys::RIGHT:
		if (GanonCheckMovement(myRoom, m_ganon[0].GetDirection()))
		{
			myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_EMPTY;
			m_ganon[0].SetPosition(m_ganon[0].GetPosX() + 1, m_ganon[0].GetPosY());
			myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_GANON;
		}
		else
		{
			if (myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX() + 1]
				== myRoom[player.GetPosY()][player.GetPosX()])
			{
				myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX()] = CHAR_EMPTY;
				m_ganon[0].SubstractHealth(1);
				player.SubstractHealth(m_ganon[0].GetDamage());
			}
			
			break;
		}
	default:
		break;
	}
}

bool Room::EnemiesCheckMovement(char** myRoom, const WildPig& wildpig, const DirectionEnemys& direction)
{
	bool movementCheck;
	switch (direction)
	{
	case DirectionEnemys::UP:
		if (myRoom[wildpig.GetPosY() - 1][wildpig.GetPosX()] == CHAR_EMPTY)
			movementCheck = true;
		else
			movementCheck = false;
		break;
	case DirectionEnemys::DOWN:
		if (myRoom[wildpig.GetPosY() + 1][wildpig.GetPosX()] == CHAR_EMPTY)
			movementCheck = true;
		else
			movementCheck = false;
		break;
	case DirectionEnemys::LEFT:
		if (myRoom[wildpig.GetPosY()][wildpig.GetPosX() - 1] == CHAR_EMPTY)
			movementCheck = true;
		else
			movementCheck = false;
		break;
	case DirectionEnemys::RIGHT:
		if (myRoom[wildpig.GetPosY()][wildpig.GetPosX() + 1] == CHAR_EMPTY)
			movementCheck = true;
		else
			movementCheck = false;
		break;
	default:
		break;
	}
	return movementCheck;
}

bool Room::GanonCheckMovement(char** myRoom, const DirectionEnemys& direction)
{
	bool movementCheck = false;
	switch (direction)
	{
	case DirectionEnemys::UP:
		if (myRoom[m_ganon[0].GetPosY() - 1][m_ganon[0].GetPosX()] == CHAR_EMPTY)
			movementCheck = true;
		else
			movementCheck = false;
		break;
	case DirectionEnemys::DOWN:
		if (myRoom[m_ganon[0].GetPosY() + 1][m_ganon[0].GetPosX()] == CHAR_EMPTY)
			movementCheck = true;
		else
			movementCheck = false;
		break;
	case DirectionEnemys::LEFT:
		if (myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX() - 1] == CHAR_EMPTY)
			movementCheck = true;
		else
			movementCheck = false;
		break;
	case DirectionEnemys::RIGHT:
		if (myRoom[m_ganon[0].GetPosY()][m_ganon[0].GetPosX() + 1] == CHAR_EMPTY)
			movementCheck = true;
		else
			movementCheck = false;
		break;
	default:
		break;
	}
	return movementCheck;
}

void Room::Attack(char** myRoom, Player& player)
{
	switch (player.GetDirection())
	{
	case Movement::UP:

		if (myRoom[player.GetPosY() - 1][player.GetPosX()] == CHAR_WILDPIG)
		{
			for (int i = 0; i < m_wildPigs.size(); i++)
			{
				if (myRoom[player.GetPosY() - 1][player.GetPosX()]
					== myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()])
				{
					myRoom[player.GetPosY() - 1][player.GetPosX()] = CHAR_EMPTY;
					m_wildPigs[i].SetAlive(false);
					m_wildPigs.erase(m_wildPigs.begin() + i);
				}
			}
		}
		else if (myRoom[player.GetPosY() - 1][player.GetPosX()] == CHAR_GANON)
		{
			m_ganon[0].SubstractHealth(1);
		}
		break;
	case Movement::LEFT:

		if (myRoom[player.GetPosY()][player.GetPosX() - 1] == CHAR_WILDPIG)
		{
			for (int i = 0; i < m_wildPigs.size(); i++)
			{
				if (myRoom[player.GetPosY()][player.GetPosX() - 1]
					== myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()])
				{
					myRoom[player.GetPosY()][player.GetPosX() - 1] = CHAR_EMPTY;
					m_wildPigs[i].SetAlive(false);
					m_wildPigs.erase(m_wildPigs.begin() + i);
				}
			}
		}
		else if (myRoom[player.GetPosY()][player.GetPosX() - 1] == CHAR_GANON)
		{
			m_ganon[0].SubstractHealth(1);
		}
		break;
	case Movement::RIGHT:

		if (myRoom[player.GetPosY()][player.GetPosX() + 1] == CHAR_WILDPIG)
		{
			for (int i = 0; i < m_wildPigs.size(); i++)
			{
				if (myRoom[player.GetPosY()][player.GetPosX() + 1]
					== myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()])
				{
					myRoom[player.GetPosY()][player.GetPosX() + 1] = CHAR_EMPTY;
					m_wildPigs[i].SetAlive(false);
					m_wildPigs.erase(m_wildPigs.begin() + i);
				}
			}
		}
		else if (myRoom[player.GetPosY()][player.GetPosX() + 1] == CHAR_GANON)
		{
			m_ganon[0].SubstractHealth(1);
		}
		break;
	case Movement::DOWN:

		if (myRoom[player.GetPosY() + 1][player.GetPosX()] == CHAR_WILDPIG)
		{
			for (int i = 0; i < m_wildPigs.size(); i++)
			{
				if (myRoom[player.GetPosY() + 1][player.GetPosX()]
					== myRoom[m_wildPigs[i].GetPosY()][m_wildPigs[i].GetPosX()])
				{
					myRoom[player.GetPosY() + 1][player.GetPosX()] = CHAR_EMPTY;
					m_wildPigs[i].SetAlive(false);
					m_wildPigs.erase(m_wildPigs.begin() + i);
				}
			}
		}
		else if (myRoom[player.GetPosY() + 1][player.GetPosX()] == CHAR_GANON)
		{
			m_ganon[0].SubstractHealth(1);
		}
		break;
	default:
		break;
	}
}

void Room::ShowHealth()const
{
	std::cout << m_ganon[0].GetHealth();
}

bool Room::GanonDie()const
{
	if (m_ganon[0].GetHealth() <= 0)
		return true;
	else
		return false;
}

void Room::Gameover(TypeOfRoom typeOfRoom)
{
	if (typeOfRoom == TypeOfRoom::CAFE)
	{
		if (m_ganon[0].GetHealth() <= 0)
		{
			std::cout << std::endl << std::endl << std::endl
				<< "				Congrats, you have defeated Ganon and you rescued Enti" << std::endl;

		}
	}
	else
	{

		std::cout << std::endl << std::endl << std::endl 
			<< "							You have lost!" << std::endl;
		std::cout << "						Good luck in your next try" << std::endl;
	}
}