#pragma once
#include "Includes.h"

class RewardObject
{
	int m_posX;
	int m_posY;

	char m_sprite;

public:

	RewardObject(const int& width,const int& height);

	void SetPosition(char** room);

	int GetPosX() const;
	
	int GetPosY() const;

	void ResetPos(const int& width, const int& height);
};