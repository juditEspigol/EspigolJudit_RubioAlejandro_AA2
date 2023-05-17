
#include "RewardObject.h"


RewardObject::RewardObject(const int& width, const int& height)
{
	isAlive = true;
	m_sprite = 'O';
	m_posX = rand() % (width - 2) + 1;
	m_posY = rand() % (width - 2) + 1;
}

void RewardObject::SetPosition(char** room)
{

}