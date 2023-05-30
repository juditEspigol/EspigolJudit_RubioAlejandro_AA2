#pragma once
#include <windows.h>
#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <queue>

#include "RewardObject.h"
#include "Player.h"
#include "Room.h"
#include "Game.h"
#include "Gem.h"

//COLORS LIST
const std::string GRAY_TEXT = "\x1b[38;5;246m";
const std::string YELLOW_TEXT = "\x1b[38;5;11m";
const std::string GREEN_TEXT = "\x1b[38;5;49m";
const std::string RED_TEXT = "\x1b[31m";
const std::string BLUE_TEXT = "\x1b[38;5;33m";
const std::string PINK_TEXT = "\x1b[38;5;5m";

// ROOM CHARS
const char CHAR_DOOR = 'D';
const char CHAR_WALL = 'X';
const char CHAR_EMPTY = ' ';
const char CHAR_POT = 'O';
const char CHAR_WILDPIG = 'S';
const char CHAR_GANON = 'G';
const char CHAR_GEM_GREEN = '$';
const char CHAR_GEM_BLUE = '#';
const char CHAR_GEM_RED = '&';

// PLAYER CHARS
const char PLAYER_UP = '^'; 
const char PLAYER_DOWN = 'v';
const char PLAYER_LEFT = '<';
const char PLAYER_RIGHT = '>';

//Enemies
const int TIME_ENEMY_MOVES = 10;
const int WILDPIGS_DAMAGE = 1;

//Ganon
const int GANON_DAMAGE = 2;

