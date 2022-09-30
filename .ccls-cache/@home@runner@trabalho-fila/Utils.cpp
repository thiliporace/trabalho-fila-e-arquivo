#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.h"

void ClearScreen()
{
#if _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

std::string __pause_hack__;
void Pause(const std::string& message)
{
	std::cout<< message;
	std::getline(std::cin, __pause_hack__);
}

