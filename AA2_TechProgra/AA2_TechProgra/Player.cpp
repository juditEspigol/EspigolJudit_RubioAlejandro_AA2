#include "Player.h"


Player::Player(std::list<Room>::iterator it)
{
	m_pos.x = it->GetWidth() / 2;
	m_pos.y = it->GetHeight() - 1;
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

int Player::GetPosX()const
{
	return m_pos.x;
}

int Player::GetPosY()const
{
	return m_pos.y;
}

void SetPosition(std::list<Room>::iterator it, char** room)
{
	//	if(player va a la nextroom)
	//		width = door;
	//		m_pos.x = 1;
	//	else (va a la prev)
	//		width = door
	//		m_pos.y = it-> m_height - 1 ;
}
