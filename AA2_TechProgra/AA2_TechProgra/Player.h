#pragma once
#include <iostream>

enum class Movement {
	UP,
	LEFT,
	RIGHT,
	DOWN
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

	Pos pos;
	
public:

	void SetName(const std::string name);

	int GetPosX()
	{
		return pos.x;
	}

	int GetPosY()
	{
		return pos.y;
	}
};

