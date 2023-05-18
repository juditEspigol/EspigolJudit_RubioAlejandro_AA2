
#include "RewardObject.h"


RewardObject::RewardObject(const int& width, const int& height)
{
	isAlive = true;
	m_sprite = CHAR_POT;
	m_posX = rand() % (width - 2) + 1;
	m_posY = rand() % (width - 2) + 1;
}

void RewardObject::SetPosition(char** room)
{

}

int RewardObject::GetPosX()const
{
	return m_posX;
}

int RewardObject::GetPosY()const
{
	return m_posY;
}

void RewardObject::ResetPos(const int& width, const int& height)
{
	m_posX = rand() % (width - 2) + 1;
	m_posY = rand() % (width - 2) + 1;
}