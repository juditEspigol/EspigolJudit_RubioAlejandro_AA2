#include "Includes.h"

int main()
{

    Player p1;

    // Create a list of all our rooms 
    std::list<Room> rooms;
    for (int i = 0; i < static_cast<int>(TypeOfRoom::COUNT); ++i)
    {
        Room newRoom(static_cast<TypeOfRoom>(i), 5 * (i + 1), 5 * (i + 1));
        rooms.push_back(newRoom);
    }

    std::list<Room>::iterator actualRoomIt = rooms.begin();

    actualRoomIt++;
   
    //Create the room which we stay in
    char** actualRoom = actualRoomIt->CreateRoom(p1);
    
    actualRoomIt->PrintRoom(actualRoom);

    actualRoomIt++;
    char** actualRoom2 = actualRoomIt->CreateRoom(p1);

    actualRoomIt->PrintRoom(actualRoom2);


 //   // CONFIGURATION
 //   const int FPS = 60;
 //   int frameCount = 0;
 //   bool userPressedKey = false;
 //   bool isPlaying = true;

 //   // GAME LOOP
 //   while (isPlaying)
 //   {

 //       // INPUT
 //       if (GetAsyncKeyState(VK_UP))
 //       {
 //           userPressedKey = true;
 //       }
 //       // UPDATE / TICK
 //      
 //       // RENDER / DRAW
 //       std::cout << frameCount++;
 //       // FRAME CONTROL
 //       Sleep(1000 / FPS);
 //   }
	//
	//// Create the dynamic array 
	//char** actualRoom;


	//

	//// Init our player 
	//Player player1(3, 3);


	//actualRoom = itRooms->InitializeRoom(player1);

	//itRooms->PrintRoom(actualRoom);
}
