#include "Game.h"

bool exitGame()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		return false;
	return true; 
}