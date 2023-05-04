#include "Includes.h"

int main()
{
    // CONFIGURATION
    const int FPS = 20;
    int frameCount = 0;


    // GAME
    bool isPlaying = true;

    char** myRoom; 

    std::ifstream config("config.txt");

    // Create a list of all our rooms 
    std::list<Room> rooms;
    if (config.is_open())
    {
        int i = 0; 
        int width, height;
        char character;
        while (config >> width >> character >> height >> character)
        {
            if (i < static_cast<int>(TypeOfRoom::COUNT))
            {
                Room newRoom(static_cast<TypeOfRoom>(i), width, height);
                rooms.push_back(newRoom);
            }
            i++; 
        }
        config.close();
    }
    else
    {
        std::cout << " --- An error has occurred trying to open the file ---";
        isPlaying = false; 
    }
    std::list<Room>::iterator actualRoomIt = rooms.begin();

    myRoom = actualRoomIt->CreateRoom(); 

    Player p1;
    p1.PosPlayerNextRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());


    // GAME LOOP
    while (isPlaying)
    {

        // MOVEMENT PLAYER 
        p1.MovementPlayer(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());

        
        if (p1.CollidesWithNextDoor(actualRoomIt->GetNextDoor()))
        {
            actualRoomIt++; 
            myRoom = actualRoomIt->CreateRoom(); 
            p1.PosPlayerNextRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
        }
        else if (p1.CollidesWithPrevDoor(actualRoomIt->GetPrevDoor(), actualRoomIt->GetHeight()))
        {
            actualRoomIt--;
            myRoom = actualRoomIt->CreateRoom();
            p1.PosPlayerPrevRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
        }


        // PRINT ROOM
        actualRoomIt->PrintRoom(myRoom);

        Sleep(1000 / FPS);
        system("cls");
        isPlaying = exitGame();
    }

    deleteDynamicArray(myRoom, actualRoomIt);
}
