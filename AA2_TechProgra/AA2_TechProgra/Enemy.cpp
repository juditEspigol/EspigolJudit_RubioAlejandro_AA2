#include "Enemy.h"

WildPig::WildPig(const int& width, const int& height)
{
	// m_sprite = CHAR_WILDPIG;
	m_posX = rand() % (width - 2) + 1; // rand() % (max - min + 1) + min;
	m_posY = rand() % (height - 2) + 1;
	m_direction = static_cast<DirectionEnemys>(rand() % 4);
}

void WildPig::SetPosition(const int& posX, const int& posY)
{
	m_posX = posX; 
	m_posY = posY;
}

int WildPig::GetPosX() const
{
	return m_posX;
}

int WildPig::GetPosY() const
{
	return m_posY;
}

//void Enemy::ResetPos(const int& width, const int& height)
//{
//	m_posX = rand() % (width - 2) + 1;
//	m_posY = rand() % (width - 2) + 1;
//}

DirectionEnemys WildPig::GetDirection() const
{
	return m_direction; 
}

void WildPig::SetDirection(DirectionEnemys newDirection)
{
	m_direction = newDirection; 
}