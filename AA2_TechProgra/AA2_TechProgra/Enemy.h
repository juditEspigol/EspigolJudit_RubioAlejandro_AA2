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

	// char m_sprite;
	DirectionEnemys m_direction; 

public: 

	WildPig(const int& width, const int& height);

	void SetPosition(const int& posX, const int& posY);

	int GetPosX() const;

	int GetPosY() const;

	void SetAlive(const bool& alive);

	DirectionEnemys GetDirection() const; 

	void SetDirection(DirectionEnemys newDirection); 
	
};

class Ganon
{
	int m_posX;
	int m_posY;
	int m_health;
	bool m_isAlive;

	// char m_sprite;
	DirectionEnemys m_direction;

public:

	Ganon(const int& width, const int& height);

	void SetPosition(const int& posX, const int& posY);

	int GetPosX() const;

	int GetPosY() const;

	bool GetAlive()const;

	void SetAlive(const bool& alive);

	DirectionEnemys GetDirection() const;

	void SetDirection(DirectionEnemys newDirection);
};