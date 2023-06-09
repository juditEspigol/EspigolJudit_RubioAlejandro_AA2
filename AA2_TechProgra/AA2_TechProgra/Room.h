#pragma once
#include "RewardObject.h"
#include "Enemy.h"

enum class Scenes;
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
	int m_numWildPigs; 
	int m_numPots; 

	std::vector<RewardObject> m_pots;
	std::vector<WildPig> m_wildPigs;
	std::vector<Ganon> m_ganon;

public:	
	
	// CONSTRUCTOR 
	Room(TypeOfRoom typeofRoom, int width, int heigth, int enemys, int pots);
	
	// GETTERS 
	int GetWidth()const;
	int GetHeight()const;
	int GetPrevDoor()const;
	int GetNextDoor()const;
	TypeOfRoom GetTypeOfRoom()const;

	// METHODS 
	char** CreateRoom(const int& width, const int& height);
	void PrintRoom(char** myRoom) const;
	void DeleteDynamicArray(char** myRoom, std::list<Room>::iterator it);
	void Gameover(TypeOfRoom typeOfRoom, const Player& player);
	// -------------------------  Pots  --------------------------------
	void CreatePots(char** myRoom);

	// ------------------------  Enemies ----------------------------
	void CreateEnemys(char** myRoom);
 	void MoveEnemys(char** myRoom, Player& player);
	void EnemiesDeath(char** myRoom, Player& player, const int& cont);
	bool EnemiesCheckMovement(char** myRoom, const WildPig& wildpig, const DirectionEnemys& direction);

	// -------------------------  Ganon  -------------------------------
	void CreateGanon(char** myRoom, const int& health);
	void MoveGanon(char** myRoom, Player& player);
	bool GanonCheckMovement(char** myRoom, const DirectionEnemys& direction, const Ganon& ganon, Player& player);
	void ShowHealth()const;
	bool GanonDie()const;
	void GanonReset(const int& health);

	// -------------------------   Link   -------------------------------
	void Attack(char** myRoom, Player& player);
};	


