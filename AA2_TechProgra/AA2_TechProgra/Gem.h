#pragma once
#include <ctime>
#include <iostream>
#include "Includes.h"

class Gem
{
private: 
	char m_type; 
	int m_value; 

public:

	// CONSTRUCTOR
	Gem(); 

	// GETTER
	char GetType() const;
	int GetValue() const;
	void GetValue(const int& value);

	// SETTER
	void SetType(const char& type); 
	
};

char spawnRandomGem();