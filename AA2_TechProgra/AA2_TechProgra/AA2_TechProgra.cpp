#include "Includes.h"

enum class InputKey
{
    K_ESC,
    K_LEFT,
    K_RIGHT,
    K_UP,
    K_DOWN,
    K_SPACE,
    COUNT,
    INVALID
};

int main()
{
    // CONFIGURATION
    const int FPS = 20;
    int frameCount = 0;

    // INITIALIZATION
    srand(time(NULL));

    bool isPlaying = true;

    bool keyboard[static_cast<int>(InputKey::COUNT)] = {};

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

    myRoom = actualRoomIt->CreateRoom(actualRoomIt->GetWidth(), actualRoomIt->GetHeight());

    Player p1;
    p1.PosPlayerNextRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());

    // GAME LOOP
    while(isPlaying)
    {
        // INPUT
        keyboard[static_cast<int>(InputKey::K_ESC)] = GetAsyncKeyState(VK_ESCAPE);
        keyboard[static_cast<int>(InputKey::K_LEFT)] = GetAsyncKeyState(VK_LEFT);
        keyboard[static_cast<int>(InputKey::K_RIGHT)] = GetAsyncKeyState(VK_RIGHT);
        keyboard[static_cast<int>(InputKey::K_UP)] = GetAsyncKeyState(VK_UP);
        keyboard[static_cast<int>(InputKey::K_DOWN)] = GetAsyncKeyState(VK_DOWN);
        keyboard[static_cast<int>(InputKey::K_SPACE)] = GetAsyncKeyState(VK_SPACE);

        // UPDATE
        // RENDER
        // FRAME CONTROL


        // MOVEMENT PLAYER 
        p1.MovementPlayer(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());


        if (p1.CollidesWithNextDoor(actualRoomIt->GetNextDoor()))
        {
            actualRoomIt++;
            myRoom = actualRoomIt->CreateRoom(actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
            p1.PosPlayerNextRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
        }
        else if (p1.CollidesWithPrevDoor(actualRoomIt->GetPrevDoor(), actualRoomIt->GetHeight()))
        {
            actualRoomIt--;
            myRoom = actualRoomIt->CreateRoom(actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
            p1.PosPlayerPrevRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
        }


        // PRINT ROOM
        actualRoomIt->PrintRoom(myRoom);
        std::cout << std::endl << " Health --> " << p1.GetHealth();
        std::cout << std::endl << " Rupias --> " << p1.GetScore();
        
        if (GetAsyncKeyState(VK_CONTROL))
            p1.SubstractHealth(1);
        

        Sleep(1000 / FPS);
        system("cls");
        isPlaying = exitGame();
    }


    deleteDynamicArray(myRoom, actualRoomIt);
}
