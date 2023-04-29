#pragma once
#include "Room.h"

enum class TypeRoom {
	CLASSROOM,
	HALL,
	CAFE
};

class Game
{
	Room actualRoom;

	Player player;
};
