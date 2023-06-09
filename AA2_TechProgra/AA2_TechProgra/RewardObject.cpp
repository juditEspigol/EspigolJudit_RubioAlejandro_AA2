
#include "RewardObject.h"

//CONSTRUCTOR

RewardObject::RewardObject(const int& width, const int& height)
{
	m_sprite = CHAR_POT;
	m_posX = rand() % (width - 2) + 1; // rand() % (max - min + 1) + min;
	m_posY = rand() % (height - 2) + 1;
}

//GETTERS

int RewardObject::GetPosX() const
{
	return m_posX;
}

int RewardObject::GetPosY() const
{
	return m_posY;
}

//SETTERS

void RewardObject::ResetPos(const int& width, const int& height)
{
	m_posX = rand() % (width - 2) + 1;
	m_posY = rand() % (width - 2) + 1;
}