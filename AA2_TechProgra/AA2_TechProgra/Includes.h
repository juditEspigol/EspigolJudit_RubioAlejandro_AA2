#pragma once
#include <windows.h>
#include <iostream>
#include <list>
#include <fstream>

#include "Player.h"
#include "Room.h"
#include "Game.h"

//COLORS LIST
#define GRAY_BACKGROUND "\x1b[48;5;246m"
#define YELLOW_TEXT "\x1b[38;5;11m"
#define GREEN_TEXT "\x1b[38;5;49m"
#define BLACK_TEXT "\x1b[30m"
#define BLACK_BACKGROUND "\x1b[40m"

// ROOM CHARS
const char CHAR_DOOR = 'P';
const char CHAR_WALL = 'X';
const char CHAR_EMPTY = ' ';

// PLAYER CHARS
const char PLAYER_UP = '^'; 
const char PLAYER_DOWN = 'v';
const char PLAYER_LEFT = '<';
const char PLAYER_RIGHT = '>';

