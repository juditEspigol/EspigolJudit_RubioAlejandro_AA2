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

	// char m_sprite;
	DirectionEnemys m_direction; 

public: 

	WildPig(const int& width, const int& height);

	void SetPosition(const int& posX, const int& posY);

	int GetPosX() const;

	int GetPosY() const;

	DirectionEnemys GetDirection() const; 

	void SetDirection(DirectionEnemys newDirection); 
	

};

class Ganon
{

};