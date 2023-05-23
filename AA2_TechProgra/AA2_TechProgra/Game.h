#pragma once
#include "Includes.h"

class Player;
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

void printInit(); 

void printMenu(); 

void printSelectExit(); 

void printSelectPlay(); 

Scenes Lose(Player& player);
