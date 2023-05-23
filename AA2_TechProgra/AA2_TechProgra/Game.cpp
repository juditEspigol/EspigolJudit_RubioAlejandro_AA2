#include "Game.h"

void printInit()
{
	std::cout << GREEN_TEXT; 
	std::cout << "============================================" << std::endl;
	std::cout << " THE LEGEND OF ZELDA: TEARS OF THE STUDENTS " << std::endl; 
	std::cout << "============================================" << std::endl;
	std::cout << "       -  by Judit Espigol & Alejandro Rubio" << std::endl; 
}

void printMenu()
{
	std::cout << GRAY_TEXT;
	std::cout << "=============================================" << std::endl;
	std::cout << "                  Main Menu                  " << std::endl;
	std::cout << "=============================================" << std::endl;
}

void printSelectExit()
{
	std::cout << "                  0. Play game               " << std::endl;
	std::cout << "               >  1. Exit                    " << std::endl;
}

void printSelectPlay()
{
	std::cout << "               >  0. Play game               " << std::endl;
	std::cout << "                  1. Exit                    " << std::endl;
}
