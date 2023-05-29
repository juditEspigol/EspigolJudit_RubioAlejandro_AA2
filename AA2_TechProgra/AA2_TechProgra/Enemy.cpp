#include "Enemy.h"

// -------------------- WildPigs ---------------------

WildPig::WildPig(const int& width, const int& height)
{
	m_posX = rand() % (width - 2) + 1; // rand() % (max - min + 1) + min;
	m_posY = rand() % (height - 2) + 1;
	m_direction = static_cast<DirectionEnemys>(rand() % 4);
	m_isAlive = true;
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

void WildPig::SetAlive(const bool& alive)
{
	m_isAlive = alive;
}

DirectionEnemys WildPig::GetDirection() const
{
	return m_direction; 
}

void WildPig::SetDirection(DirectionEnemys newDirection)
{
	m_direction = newDirection; 
}

// --------------------- Ganon --------------------

Ganon::Ganon(const int& width, const int& height)
{
	m_posX = rand() % (width - 2) + 1; 
	m_posY = rand() % (height - 2) + 1;
	m_direction = static_cast<DirectionEnemys>(rand() % 4);
	m_health = 10;
	m_isAlive = true;
}

void Ganon::SetPosition(const int& posX, const int& posY)
{
	m_posX = posX;
	m_posY = posY;
}

int Ganon::GetPosX() const
{
	return m_posX;
}

int Ganon::GetPosY() const
{
	return m_posY;
}

bool Ganon::GetAlive()const
{
	return m_isAlive;
}

void Ganon::SetAlive(const bool& alive)
{
	m_isAlive = alive;
}

DirectionEnemys Ganon::GetDirection() const
{
	return m_direction;
}

void Ganon::SetDirection(DirectionEnemys newDirection)
{
	m_direction = newDirection;
}