#pragma once
//#include "Includes.h"
#include "Room.h"
enum class Movement 
{
	UP,
	LEFT,
	RIGHT,
	DOWN
};

class Player
{
private:
	// ATTRIBUTES 
	std::string m_name;

	int m_posX; 
	int m_posY;

	Movement m_move; 
	char m_sprite;
	int m_health;
	int m_score;

	// METHODS 
	void SetPosition(char** myRoom);

	bool CheckNextPos(char** myRoom);
	// Clean the char of your pos before move
	void ClearPosPlayer(char** myRoom);
	
public:

	// CONSTRUCTOR
	Player(const int& health);

	

	// GETTERS
	std::string GetName() const; 
	int GetPosX()const;
	int GetPosY()const;
	int GetScore()const;
	int GetHealth()const;
	Movement GetDirection()const;
	

	// METHODS 
	void PrintPlayer(const Movement& movement);

	void MovementPlayer(char** myRoom, const int& width, const int& height);

	void Attack(char** myRoom, const Movement& move);

	void PosPlayerPrevRoom(char** myRoom, const int& width, const int& height);
	void PosPlayerNextRoom(char** myRoom, const int& width, const int& height);

	bool CollidesWithPrevDoor(const int& prevDoorX, const int& height);
	bool CollidesWithNextDoor(const int& nextDoorX);
	void EnemiesAddScore(const int& value);
	void GemAddScore(char** myRoom, const Movement& move);

	void SubstractHealth(const int& value);
	void ResetPlayer(const int& health);
	
	

	

	
};

