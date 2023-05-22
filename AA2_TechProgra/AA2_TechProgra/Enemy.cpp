#include "Enemy.h"

WildPig::WildPig(const int& width, const int& height)
{
	// m_sprite = CHAR_WILDPIG;
	m_posX = rand() % (width - 2) + 1; // rand() % (max - min + 1) + min;
	m_posY = rand() % (height - 2) + 1;
	m_verticalDirection = rand() & 2; 
}

void WildPig::SetPosition(char** room)
{

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