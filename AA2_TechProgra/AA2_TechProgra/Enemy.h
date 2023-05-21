#pragma once
#include "Includes.h"

class Enemy
{
	int m_posX;
	int m_posY;

	char m_sprite;

public: 

	Enemy(const int& width, const int& height);

	void SetPosition(char** room);

	int GetPosX() const;

	int GetPosY() const;
};