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
	

public:	
	std::vector<Ganon> m_ganon;
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
	void DeleteDynamicArray(char** myRoom, std::list<Room>::iterator it);
	// -------------------------  Pots  --------------------------------
	void CreatePots(char** myRoom, const int& numPots);

	// ------------------------  Enemies ----------------------------
	void CreateEnemys(char** myRoom, const int& numPigs);
 	void MoveEnemys(char** myRoom, Player& player, int& cont); // S'haura d'arreglar
	bool EnemiesCheckMovement(char** myRoom, const WildPig& wildpig, const DirectionEnemys& direction);
	void Attack(char** myRoom, Player& player);

	// -------------------------  Ganon  -------------------------------
	void CreateGanon(char** myRoom);
	void MoveGanon(char** myRoom, Player& player, )
};

