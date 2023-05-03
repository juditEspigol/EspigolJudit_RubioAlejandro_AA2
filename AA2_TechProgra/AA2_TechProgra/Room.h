#pragma once
#include "Includes.h"

enum class TypeOfRoom {
	CLASSROOM,
	HALL,
	CAFE,
	COUNT
};

class Room
{
private:

	TypeOfRoom m_typeRoom;

	int m_prevDoor;
	int m_nextDoor;

	int m_width;
	int m_height;

public:	

	Room(TypeOfRoom typeofRoom, int numRows, int numColums);



	char** CreateRoom();

	void PrintRoom(char** myRoom) const;

	int GetWidth()const;

	int GetHeight()const;

	int GetNextDoor()const;

	int GetPrevDoor()const;
};

void deleteDynamicArray(char** myRoom, std::list<Room>::iterator it);
