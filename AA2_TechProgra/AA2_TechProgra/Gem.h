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
	// Constructor
	Gem(); 

	// Getter
	char GetType() const;
	int GetValue() const; 
	// Setter
	void SetType(const char& type); 
	void GetValue(const int& value); 
};

char spawnRandomGem();