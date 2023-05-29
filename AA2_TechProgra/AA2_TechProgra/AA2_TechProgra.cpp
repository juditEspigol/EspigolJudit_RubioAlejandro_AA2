#include "Includes.h"

int main()
{
    srand(time(NULL));

    // CONFIGURATION
    const int FPS = 20;
    int frameCount = 0;
    int cont = 0;

    // INITIALIZATION
    Scenes actualScene = Scenes::GAME;

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
    }
    std::list<Room>::iterator actualRoomIt = rooms.begin();

    myRoom = actualRoomIt->CreateRoom(actualRoomIt->GetWidth(), actualRoomIt->GetHeight());

    Player p1;
    p1.PosPlayerNextRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
    actualRoomIt->CreatePots(myRoom, 4);
    actualRoomIt->CreateEnemys(myRoom, 4);
    
    bool selectPlay = true;

    while (actualScene != Scenes::EXIT)
    {
        if (p1.GetHealth() == 0)
            std::cout << ' a';
        // INPUT 
        keyboard[static_cast<int>(InputKey::K_ESC)] = GetAsyncKeyState(VK_ESCAPE);
        keyboard[static_cast<int>(InputKey::K_LEFT)] = GetAsyncKeyState(VK_LEFT);
        keyboard[static_cast<int>(InputKey::K_RIGHT)] = GetAsyncKeyState(VK_RIGHT);
        keyboard[static_cast<int>(InputKey::K_UP)] = GetAsyncKeyState(VK_UP);
        keyboard[static_cast<int>(InputKey::K_DOWN)] = GetAsyncKeyState(VK_DOWN);
        keyboard[static_cast<int>(InputKey::K_SPACE)] = GetAsyncKeyState(VK_SPACE);

        // UPDATE
        switch (actualScene)
        {
        case Scenes::INIT:

            // UPDATE / TICK
            if (frameCount == 20)
            {
                actualScene = Scenes::MENU;
                frameCount = 0;
            }
            frameCount++;

            // RENDER / DRAW
            printInit();
            break;
        case Scenes::MENU:

            // UPDATE / TICK
            if (keyboard[static_cast<int>(InputKey::K_DOWN)]) // K_DOWN == TRUE
                selectPlay = false;
            else if (keyboard[static_cast<int>(InputKey::K_UP)])
                selectPlay = true;

            if (selectPlay && keyboard[static_cast<int>(InputKey::K_SPACE)])
                actualScene = Scenes::GAME;
            else if (!selectPlay && keyboard[static_cast<int>(InputKey::K_SPACE)])
                actualScene = Scenes::EXIT;

            // RENDER / DRAW
            printMenu();
            if (selectPlay)
                printSelectPlay();
            else
                printSelectExit();
            break;
        case Scenes::GAME:

                if (p1.GetHealth() <= 0)
                {
                    actualScene = Scenes::GAMEOVER;
                    break;
                }

                if (actualRoomIt->GetTypeOfRoom() == TypeOfRoom::CAFE && actualRoomIt->GanonDie())
                    actualScene = Scenes::GAMEOVER;
                // MOVEMENT PLAYER 
                p1.MovementPlayer(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());

                if (keyboard[static_cast<int>(InputKey::K_SPACE)])
                    actualRoomIt->Attack(myRoom, p1);

                if (p1.CollidesWithNextDoor(actualRoomIt->GetNextDoor()))
                {
                    actualRoomIt->DeleteDynamicArray(myRoom, actualRoomIt);
                    actualRoomIt++;
                    myRoom = actualRoomIt->CreateRoom(actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
                    p1.PosPlayerNextRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
                    actualRoomIt->CreatePots(myRoom, 4);
                    actualRoomIt->CreateEnemys(myRoom, 4);
                    if(actualRoomIt->GetTypeOfRoom() == TypeOfRoom::CAFE)
                        actualRoomIt->CreateGanon(myRoom);
                }
                else if (p1.CollidesWithPrevDoor(actualRoomIt->GetPrevDoor(), actualRoomIt->GetHeight()))
                {
                    actualRoomIt--;
                    myRoom = actualRoomIt->CreateRoom(actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
                    p1.PosPlayerPrevRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
                    actualRoomIt->CreatePots(myRoom, 4);
                    actualRoomIt->CreateEnemys(myRoom, 4);
                }
                if (cont == timeEnemyMoves)
                {
                    actualRoomIt->MoveEnemys(myRoom, p1); 
                    if (actualRoomIt->GetTypeOfRoom() == TypeOfRoom::CAFE)
                    {
                        actualRoomIt->MoveGanon(myRoom, p1); 
                    }
                    cont = 0;
                }

                // PRINT ROOM
                actualRoomIt->PrintRoom(myRoom);

                std::cout << std::endl << " Health --> " << p1.GetHealth();
                if (actualRoomIt->GetTypeOfRoom() == TypeOfRoom::CAFE)
                {
                    std::cout << "           Ganon Health --> ";
                    actualRoomIt->ShowHealth();
                }
                std::cout << std::endl << " Rupias --> " << p1.GetScore();
   
            break;
        case Scenes::GAMEOVER:
            actualRoomIt->Gameover(actualRoomIt->GetTypeOfRoom());
            if (frameCount == 50)
            {
                actualScene = Scenes::MENU;
                frameCount = 0;
            }
            frameCount++;
            break;
        default:
            actualScene = Scenes::EXIT; 
            break;
        }
        if (keyboard[static_cast<int>(InputKey::K_ESC)])
            actualScene = Scenes::EXIT;

        // FRAME CONTROL 
        cont++;
        Sleep(1000 / FPS);
        system("cls");
    }
    actualRoomIt->DeleteDynamicArray(myRoom, actualRoomIt);
}
