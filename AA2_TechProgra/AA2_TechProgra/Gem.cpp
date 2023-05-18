#include "Gem.h"

char spawnRandomGem()
{
	char charToReturn = ' ';
	int typeOfGem;
	typeOfGem = rand() % 3;

	switch (typeOfGem)
	{
	case 0:
		charToReturn = CHAR_GEM_GREEN; // Green gem
		break;
	case 1:
		charToReturn = CHAR_GEM_BLUE; // Blue gem
		break;
	case 2:
		charToReturn = CHAR_GEM_RED; //Red gem
	default:
		break;
	}
	return charToReturn;
}