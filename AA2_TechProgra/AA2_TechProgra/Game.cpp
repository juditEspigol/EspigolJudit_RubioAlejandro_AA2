#include "Game.h"

void exitGame(bool& isPlaying)
{
	if (GetAsyncKeyState(VK_ESCAPE))
		isPlaying = false;
}