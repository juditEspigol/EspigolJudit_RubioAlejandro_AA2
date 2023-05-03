#include "Includes.h"
#include <fstream>

int main()
{
    char** myRoom; 

    Player p1; 

    std::ifstream config("config.txt");

    // Create a list of all our rooms 
    std::list<Room> rooms;
    for (int i = 0; i < static_cast<int>(TypeOfRoom::COUNT); ++i)
    {
        Size size[static_cast<int>(TypeOfRoom::COUNT)];
        int width, height;
        char basura;

        if (config.is_open())
        {
            int j = 0;
            while (config >> width >> basura >> height && j < 3)
            {
                size[j].width = width;
                size[j].height = height;
                j++;
            }
            Room newRoom(static_cast<TypeOfRoom>(i), size[i].width, size[i].height);
            rooms.push_back(newRoom);
        }
        else
        {
            std::cout << " An error has occurred trying to open the file";
        }
    }

    config.close();
    std::list<Room>::iterator actualRoomIt = rooms.begin();

    myRoom = actualRoomIt->CreateRoom(); 

    p1.InsertPlayer(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());

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

        exitGame(isPlaying);

        Sleep(1000 / FPS);

        system("cls");
    }
}
