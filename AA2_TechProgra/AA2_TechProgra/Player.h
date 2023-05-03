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

	std::string m_name;

	int m_posX; 
	int m_posY;

	Movement m_move; 
	char m_sprite;
	
public:

	Player();


	void InsertPlayer(char** myRoom, const int& width, const int& height); 

	void SetPosition(char** myRoom); 

	void MovementPlayer(char** myRoom,const int& width,const int& height);

	bool CheckNextPos(char** myRoom);

	void ClearPosPlayer(char** myRoom);

	bool CollidesWithNextDoor(const int& nextDoorX); 

	bool CollidesWithPrevDoor(const int& prevDoorX,const int& height); 

	void SetName(const std::string name);

	void PrintPlayer(const Movement& movement);

	char GetSprite()const;

	int GetPosX()const;

	int GetPosY()const;
	
};

