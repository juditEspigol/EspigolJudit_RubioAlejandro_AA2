#pragma once
#include "Includes.h"

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

	// METHODS 
	void SetPosition(char** myRoom);

	bool CheckNextPos(char** myRoom);
	// Clean the char of your pos before move
	void ClearPosPlayer(char** myRoom);
	
public:
	// CONSTRUCTOR
	Player();

	int m_score;

	// GETTERS
	std::string GetName() const; 
	int GetPosX() const;
	int GetPosY() const;
	int GetScore()const;

	// METHODS 
	void PrintPlayer(const Movement& movement);

	void MovementPlayer(char** myRoom, const int& width, const int& height);

	void Attack(char** myRoom, const Movement& move);

	void PosPlayerPrevRoom(char** myRoom, const int& width, const int& height);
	void PosPlayerNextRoom(char** myRoom, const int& width, const int& height);


	bool CollidesWithPrevDoor(const int& prevDoorX, const int& height);
	bool CollidesWithNextDoor(const int& nextDoorX);
	bool CheckGemInNextPosition(char** myRoom, const Movement& move);
	void AddScore(char** myRoom, const Movement& move);

	

	
};

