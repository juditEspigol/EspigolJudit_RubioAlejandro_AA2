#include "Includes.h"

int main()
{
    char** myRoom; 

    Player p1; 

    // Create a list of all our rooms 
    std::list<Room> rooms;
    for (int i = 0; i < static_cast<int>(TypeOfRoom::COUNT); ++i)
    {
        Room newRoom(static_cast<TypeOfRoom>(i), 5 * (i + 1), 5 * (i + 1));
        rooms.push_back(newRoom);
    }
    std::list<Room>::iterator actualRoomIt = rooms.begin();

    myRoom = actualRoomIt->CreateRoom(); 

    p1.InsertPlayer(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());

    actualRoomIt->PrintRoom(myRoom);

    // CONFIGURATION
    const int FPS = 60;
    int frameCount = 0;
    bool userPressedKey = false;
    bool isPlaying = true;

    // GAME LOOP
    while (isPlaying)
    {
        // Movement del player 

        p1.MovementPlayer(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());

        if (p1.CollidesWithNextDoor(actualRoomIt->GetNextDoor()))
        {
            actualRoomIt++; 
            myRoom = actualRoomIt->CreateRoom(); 
            p1.InsertPlayer(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight()); 
        }
        else if (p1.CollidesWithPrevtDoor(actualRoomIt->GetPrevDoor(), actualRoomIt->GetHeight()))
        {
            actualRoomIt--;
            myRoom = actualRoomIt->CreateRoom();
            p1.InsertPlayer(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
        }


        actualRoomIt->PrintRoom(myRoom);
       
        // INPUT
        
        // update / tick
       
        // render / draw
        
        // frame control
        Sleep(1000 / FPS);

        system("cls");
    }
    /*  

    actualRoomIt++;
   
    //Create the room which we stay in
    char** actualRoom = actualRoomIt->CreateRoom(p1);
    
    actualRoomIt->PrintRoom(actualRoom);

    actualRoomIt++;
    char** actualRoom2 = actualRoomIt->CreateRoom(p1);

    actualRoomIt->PrintRoom(actualRoom2);

    */
}
