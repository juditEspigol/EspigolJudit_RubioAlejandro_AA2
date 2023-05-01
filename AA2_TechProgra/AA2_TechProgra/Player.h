#pragma once
#include <iostream>
#include <list>
#include "Room.h"

enum class Movement {
	UP = '^',
	LEFT = '<',
	RIGHT = '>',
	DOWN = 'v'
};

class Player
{
private:

	struct Pos
	{
		int x;
		int y;
	};

	std::string m_name;

	Pos m_pos;
	char m_sprite;
	
public:

	Player(std::list<Room>::iterator it);

	void SetName(const std::string name);

	void PrintPlayer(const Movement& movement);

	int GetPosX()const;

	int GetPosY()const;
};

