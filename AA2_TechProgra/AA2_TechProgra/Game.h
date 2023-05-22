#pragma once
#include "Includes.h"

enum class Scenes
{
    INIT,
    MENU,
    GAME,
    GAMEOVER,
    EXIT
};

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

bool exitGame();

void printInit(); 

void printMenu(); 

void printSelectExit(); 

void printSelectPlay(); 
