#pragma once
#include "Includes.h"

enum class Movement {
	UP = '^',
	LEFT = '<',
	RIGHT = '>',
	DOWN = 'v'
};

class Player
{
private:

	std::string m_name = "Link";

	int m_posX; 
	int m_posY;

	Movement m_move; 
	char m_sprite = static_cast<char>(Movement::UP);
	
public:

	void InsertPlayer(char**& myRoom, const int& width, const int& height); 

	void SetPosition(char**& myRoom); 

	void MovementPlayer(char** myRoom, int width, int height);

	bool CollidesWithNextDoor(int nextDoorX); 

	bool CollidesWithPrevtDoor(int prevDoorX, int height); 

	void SetName(const std::string name);

	void PrintPlayer(const Movement& movement);

	char GetSprite()const; 

	int GetPosX()const;

	int GetPosY()const;
};

