#include "Player.h"


void Player::InsertPlayer(char**& myRoom, const int& width, const int& height)
{
	m_posX = width / 2;
	m_posY = height - 2;

	SetPosition(myRoom); 
}

//Method private
void Player::SetPosition(char**& myRoom)
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

bool Player::CollidesWithNextDoor(int nextDoorX)
{
	if (m_posX == nextDoorX && m_posY == 0)
		return true; 
	return false; 
}
bool Player::CollidesWithPrevtDoor(int prevDoorX, int height)
{
	if (m_posX == prevDoorX && m_posY == height - 1)
		return true;
	return false;
}


void Player::MovementPlayer(char** myRoom, int width, int height)
{
	// detectar si el moviment es valid o no
	// moures
	// canviar d'sprite
	// eliminar las seva posicio anterior a l'array 


	// GetAsyncKeyState(VK_ESCAPE) == boolean // fa sol el cin
	if (GetAsyncKeyState(VK_UP))
	{
		if (m_posY > 0)
		{
			m_move = Movement::UP;
			m_posY--;
			SetPosition(myRoom);
		}
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (m_posY < height - 1)
		{
			m_move = Movement::DOWN;
			m_posY++;
			SetPosition(myRoom);
		}
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (m_posX > 0)
		{
			m_move = Movement::UP;
			m_posX--;
			SetPosition(myRoom);
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_posX < width - 1)
		{
			m_move = Movement::DOWN;
			m_posX++;
			SetPosition(myRoom);
		}
		
	}

	

}


/*

void SetPosition(std::list<Room>::iterator it, char** room)
{
	//	if(player va a la nextroom)
	//		width = door;
	//		m_pos.x = 1;
	//	else (va a la prev)
	//		width = door
	//		m_pos.y = it-> m_height - 1 ;
}
*/