#include "Gem.h"

// CONSTRUCTOR
Gem::Gem()
{
int randomGem = rand() % 3;
switch (randomGem)
{
case 0:
	m_type = CHAR_GEM_GREEN; // '$'
	m_value = 1;
	break;
case 1:
	m_type = CHAR_GEM_BLUE; // '#'
	m_value = 5;
	break;
case 2:
	m_type = CHAR_GEM_RED; // '&'
	m_value = 20;
default:
	break;
}
	}

// Getter
char Gem::GetType() const
{
	return m_type;
}
int Gem::GetValue() const
{
	return m_value; 
}
// Setter
void Gem::SetType(const char& type)
{
	m_type = type;
}
void Gem::GetValue(const int& value)
{
	m_value = value; 
}

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