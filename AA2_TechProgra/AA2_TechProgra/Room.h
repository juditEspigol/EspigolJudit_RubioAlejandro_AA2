#pragma once
#include "Includes.h"

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

public:	
	// CONSTRUCTOR 
	Room(TypeOfRoom typeofRoom, int width, int heigth);

	// GETTERS 
	int GetWidth()const;
	int GetHeight()const;

	int GetPrevDoor()const;
	int GetNextDoor()const;

	// METHODS 
	char** CreateRoom();
	void PrintRoom(char** myRoom) const;
};

void deleteDynamicArray(char** myRoom, std::list<Room>::iterator it);
