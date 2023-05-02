#include "Player.h"

Player::Player()
{
	m_name = "Link";
	m_sprite = static_cast<char>(Movement::UP);
}

void Player::InsertPlayer(char** myRoom, const int& width, const int& height)
{
	m_posX = width / 2;
	m_posY = height - 2;

	SetPosition(myRoom); 
}

//Method private
void Player::SetPosition(char** myRoom)
{
	myRoom[m_posY][m_posX] = m_sprite;
}

void Player::SetName(const std::string name)
{
	m_name = name;
}

void Player::PrintPlayer(const Movement& movement)
{
	switch (movement)
	{
	case Movement::UP:
			m_sprite = static_cast<char>(Movement::UP);
		break;
	case Movement::LEFT:
		m_sprite = static_cast<char>(Movement::LEFT);
		break;
	case Movement::RIGHT:
		m_sprite = static_cast<char>(Movement::RIGHT);
		break;
	case Movement::DOWN:
		m_sprite = static_cast<char>(Movement::DOWN);
		break;
	default:
		break;
	}

	std::cout << m_sprite;
}

char Player::GetSprite()const
{
	return m_sprite;
}

int Player::GetPosX()const
{
	return m_posX;
}

int Player::GetPosY()const
{
	return m_posY;
}

bool Player::CollidesWithNextDoor(const int& nextDoorX)
{
	if (m_posX == nextDoorX && m_posY == 0)
		return true; 
	return false; 
}

bool Player::CollidesWithPrevtDoor(const int& prevDoorX,const int& height)
{
	if (m_posX == prevDoorX && m_posY == height - 1)
		return true;
	return false;
}


void Player::MovementPlayer(char** myRoom, const int& width, const int& height)
{
	// detectar si el moviment es valid o no
	// moures
	// canviar d'sprite
	// eliminar las seva posicio anterior a l'array 


	// GetAsyncKeyState(VK_ESCAPE) == boolean // fa sol el cin
	if (GetAsyncKeyState(VK_UP))
	{
		m_move = Movement::UP;
		m_sprite = static_cast<char>(m_move);

		if (CheckNextPos( myRoom))
		{
			ClearPosPlayer(myRoom);
			m_posY--;
		}

	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_move = Movement::DOWN;
		m_sprite = static_cast<char>(m_move);

		if (CheckNextPos(myRoom))
		{
			ClearPosPlayer(myRoom);
			m_posY++;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		m_move = Movement::LEFT;
		m_sprite = static_cast<char>(m_move);

		if (CheckNextPos(myRoom))
		{
			ClearPosPlayer(myRoom);
			m_posX--;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		m_move = Movement::RIGHT;
		m_sprite = static_cast<char>(m_move);
		if (CheckNextPos(myRoom))
		{
			ClearPosPlayer(myRoom);
			m_posX++;
		}
	}
	SetPosition(myRoom); 
}

void Player::ClearPosPlayer(char** myRoom)
{
	myRoom[m_posY][m_posX] = CHAR_EMPTY;
}

bool Player::CheckNextPos(char** myRoom)
{
	bool canMove = true;

	switch (m_move)
	{
	case Movement::UP:
		if (myRoom[m_posY - 1][m_posX] == CHAR_WALL)
			canMove = false;
		break;
	case Movement::LEFT:
		if (myRoom[m_posY][m_posX - 1] == CHAR_WALL)
			canMove = false;
		break;
	case Movement::RIGHT:
		if (myRoom[m_posY][m_posX + 1] == CHAR_WALL)
			canMove = false;
		break;
	case Movement::DOWN:
		if (myRoom[m_posY + 1][m_posX] == CHAR_WALL)
			canMove = false;
		break;
	default:
		break;
	}

	return canMove;
}
