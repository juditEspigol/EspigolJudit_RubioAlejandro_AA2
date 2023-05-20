#pragma once
#include "Includes.h"

class RewardObject
{
	int m_posX;
	int m_posY;

	bool isAlive;

	char m_sprite;
	//Gem m_gem;

public:

	RewardObject(const int& width,const int& height);

	void SetPosition(char** room);

	int GetPosX() const;
	
	int GetPosY() const;

	void ResetPos(const int& width, const int& height);
};