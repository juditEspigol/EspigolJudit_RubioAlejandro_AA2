#include "Game.h"

class Game
{
private:

public:

};


bool exitGame()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		return false;
	return true; 
}