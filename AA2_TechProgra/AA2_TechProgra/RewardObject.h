#pragma once
#include "Includes.h"

class RewardObject
{
	int m_posX;
	int m_posY;

	char m_sprite;

public:

	//CONSTRUCTOR
	RewardObject(const int& width,const int& height);

	//GETTERS
	int GetPosX() const;
	int GetPosY() const;

	//METHODS
	void ResetPos(const int& width, const int& height);
};