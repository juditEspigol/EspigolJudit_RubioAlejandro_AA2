#pragma once
#include "RewardObject.h"
#include "Enemy.h"

class Player;
class RewardObject;
enum class TypeOfRoom 
{
	CLASSROOM,
	HALL,
	CAFE,
	COUNT
};

void printTypeOfRoom(TypeOfRoom typeRoom); 

class Room
{
private:
	// ATTRIBUTES
	TypeOfRoom m_typeRoom;

	int m_prevDoor;
	int m_nextDoor;

	int m_width;
	int m_height;

	std::vector<RewardObject> m_pots;
	std::vector<WildPig> m_wildPigs;
	//Ganon ganon;

public:	
	
	// CONSTRUCTOR 
	Room(TypeOfRoom typeofRoom, int width, int heigth);

	// GETTERS 
	int GetWidth()const;
	int GetHeight()const;

	int GetPrevDoor()const;
	int GetNextDoor()const;

	// METHODS 
	char** CreateRoom(const int& width, const int& height);
	void PrintRoom(char** myRoom) const;

	// -------------------------  Pots  --------------------------------
	void CreatePots(char** myRoom, const int& numPots);

	// ------------------------  Enemies ----------------------------
	void CreateEnemys(char** myRoom, const int& numPigs);
 	void MoveEnemys(char** myRoom, Player& player); // S'haura d'arreglar
	bool EnemiesCheckMovement(char** myRoom, const WildPig& wildpig, const DirectionEnemys& direction);
	
};

void deleteDynamicArray(char** myRoom, std::list<Room>::iterator it);

