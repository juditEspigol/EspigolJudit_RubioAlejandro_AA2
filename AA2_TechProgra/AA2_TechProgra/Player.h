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

	std::string m_name;

	struct Pos
	{
		int x;
		int y;
	};

	void SetName(const std::string name);
};

