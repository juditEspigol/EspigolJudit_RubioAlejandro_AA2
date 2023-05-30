#include "Includes.h"

int main()
{
	srand(time(NULL));

	// CONFIGURATION
	const int FPS = 20;
	int frameCount = 0;
	int cont = 0;

	// INITIALIZATION
	Scenes actualScene = Scenes::INIT;

	bool keyboard[static_cast<int>(InputKey::COUNT)] = {};

	char** myRoom;

	std::ifstream config("config.txt");
	int livesLink, livesGanon, link, ganon;
	// Create a list of all our rooms 
	std::list<Room> rooms;
	if (config.is_open())
	{
		int i = 0;
		int width, height, enemys, pots;
		char character;

		while (config >> link >> character >> ganon >> character)
		{
			livesLink = link; 
			livesGanon = ganon;
			while (config >> width >> character >> height >> character
				>> enemys >> character >> pots >> character)
			{
				if (i < static_cast<int>(TypeOfRoom::COUNT))
				{
					Room newRoom(static_cast<TypeOfRoom>(i), width, height, enemys, pots);
					rooms.push_back(newRoom);
				}
				i++;
			}
		}
		config.close();
	}
	else
	{
		std::cout << " --- An error has occurred trying to open the file ---";
	}
	std::list<Room>::iterator actualRoomIt = rooms.begin();

	myRoom = actualRoomIt->CreateRoom(actualRoomIt->GetWidth(), actualRoomIt->GetHeight());

	Player p1(livesLink);
	p1.PosPlayerNextRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
	actualRoomIt->CreatePots(myRoom);
	actualRoomIt->CreateEnemys(myRoom);

	bool selectPlay = true;

	while (actualScene != Scenes::EXIT)
	{
		// INPUT 
		keyboard[static_cast<int>(InputKey::K_ESC)] = GetAsyncKeyState(VK_ESCAPE);
		keyboard[static_cast<int>(InputKey::K_LEFT)] = GetAsyncKeyState(VK_LEFT);
		keyboard[static_cast<int>(InputKey::K_RIGHT)] = GetAsyncKeyState(VK_RIGHT);
		keyboard[static_cast<int>(InputKey::K_UP)] = GetAsyncKeyState(VK_UP);
		keyboard[static_cast<int>(InputKey::K_DOWN)] = GetAsyncKeyState(VK_DOWN);
		keyboard[static_cast<int>(InputKey::K_SPACE)] = GetAsyncKeyState(VK_SPACE);
		keyboard[static_cast<int>(InputKey::K_RETURN)] = GetAsyncKeyState(VK_RETURN);

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

			if (selectPlay && keyboard[static_cast<int>(InputKey::K_RETURN)])
				actualScene = Scenes::GAME;
			else if (!selectPlay && keyboard[static_cast<int>(InputKey::K_RETURN)])
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
				actualRoomIt->CreatePots(myRoom);
				actualRoomIt->CreateEnemys(myRoom);
				if (actualRoomIt->GetTypeOfRoom() == TypeOfRoom::CAFE)
					actualRoomIt->CreateGanon(myRoom, livesGanon);
			}
			else if (p1.CollidesWithPrevDoor(actualRoomIt->GetPrevDoor(), actualRoomIt->GetHeight()))
			{
				actualRoomIt--;
				myRoom = actualRoomIt->CreateRoom(actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
				p1.PosPlayerPrevRoom(myRoom, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
				actualRoomIt->CreatePots(myRoom);
				actualRoomIt->CreateEnemys(myRoom);
			}
			if (cont == TIME_ENEMY_MOVES)
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
			cont++;
			break;
		case Scenes::GAMEOVER:
			actualRoomIt->Gameover(actualRoomIt->GetTypeOfRoom(), p1);
			if (frameCount == 50)
			{
				actualScene = Scenes::MENU;
				frameCount = 0;
				p1.ResetPlayer(livesLink, actualRoomIt->GetWidth(), actualRoomIt->GetHeight());
				if(actualRoomIt->GetTypeOfRoom() == TypeOfRoom::CAFE)
					actualRoomIt->GanonReset(livesGanon);
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
		Sleep(1000 / FPS);
		system("cls");
	}
	actualRoomIt->DeleteDynamicArray(myRoom, actualRoomIt);
}
