#pragma once
#include <iostream>

enum class DirectionEnemys
{
	UP, 
	DOWN, 
	LEFT, 
	RIGHT
};

class WildPig
{
	int m_posX;
	int m_posY;
	bool m_isAlive;

	DirectionEnemys m_direction; 

public: 

	//CONSTRUCTOR
	WildPig(const int& width, const int& height);

	//GETTERS
	int GetPosX() const;
	int GetPosY() const;
	DirectionEnemys GetDirection() const;

	//SETTERS
	void SetPosition(const int& posX, const int& posY);
	void SetAlive(const bool& alive);
	void SetDirection(DirectionEnemys newDirection); 
};

class Ganon
{
	int m_posX;
	int m_posY;
	int m_health;
	bool m_isAlive;

	DirectionEnemys m_direction;

public:

	//CONSTRUCTOR
	Ganon(const int& width, const int& height, const int& health);

	//GETTERS
	int GetPosX() const;

	int GetPosY() const;

	bool GetAlive()const;

	int GetHealth()const;

	DirectionEnemys GetDirection() const;

	//SETTERS
	void SetPosition(const int& posX, const int& posY);
	void SetAlive(const bool& alive);
	void SetHealth(const int& health);
	void SetDirection(DirectionEnemys newDirection);

	//METHODS 
	void RandomDirection();
	void SubstractHealth(const int& value);
};