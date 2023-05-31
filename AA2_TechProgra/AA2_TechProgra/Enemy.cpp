#include "Enemy.h"

// -------------------- WildPigs ---------------------

//CONSTRUCTOR

WildPig::WildPig(const int& width, const int& height)
{
	m_posX = rand() % (width - 2) + 1; // rand() % (max - min + 1) + min;
	m_posY = rand() % (height - 2) + 1;
	m_direction = static_cast<DirectionEnemys>(rand() % 4);
	m_isAlive = true;
}

//GETTERS

int WildPig::GetPosX() const
{
	return m_posX;
}

int WildPig::GetPosY() const
{
	return m_posY;
}

DirectionEnemys WildPig::GetDirection() const
{
	return m_direction;
}

//SETTERS

void WildPig::SetPosition(const int& posX, const int& posY)
{
	m_posX = posX;
	m_posY = posY;
}

void WildPig::SetAlive(const bool& alive)
{
	m_isAlive = alive;
}

void WildPig::SetDirection(DirectionEnemys newDirection)
{
	m_direction = newDirection; 
}

// --------------------- Ganon --------------------

// CONSTRUCTOR

Ganon::Ganon(const int& width, const int& height, const int& health)
{
	m_posX = rand() % (width - 2) + 1; 
	m_posY = rand() % (height - 2) + 1;
	m_direction = static_cast<DirectionEnemys>(rand() % 4);
	m_health = health;
	m_isAlive = true;
}

// GETTERS

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

int Ganon::GetHealth()const
{
	return m_health;
}

DirectionEnemys Ganon::GetDirection() const
{
	return m_direction;
}

// SETTERS

void Ganon::SetPosition(const int& posX, const int& posY)
{
	m_posX = posX;
	m_posY = posY;
}

void Ganon::SetAlive(const bool& alive)
{
	m_isAlive = alive;
}

void Ganon::SetHealth(const int& health)
{
	m_health = health;
}

void Ganon::SetDirection(DirectionEnemys newDirection)
{
	m_direction = newDirection;
}


//METHODS
void Ganon::RandomDirection()
{
	m_direction = static_cast<DirectionEnemys>(rand() % 4);
}

void Ganon::SubstractHealth(const int& value)
{
	m_health -= value;
}