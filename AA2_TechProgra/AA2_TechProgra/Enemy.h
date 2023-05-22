#pragma once
#include <iostream>

class WildPig
{
	int m_posX;
	int m_posY;

	// char m_sprite;
	bool m_verticalDirection; 

public: 

	WildPig(const int& width, const int& height);

	void SetPosition(char** room);

	int GetPosX() const;

	int GetPosY() const;
};

class Ganon
{

};