#include <iostream>
#include "Game.h"


int main()
{
	std::cout << "Welcome to TicTacToe Version 1.0" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	Game g;
	g.Run();
	std::cout << "Thanks for playing!" << std::endl;
	char i;
	std::cin >> i;

	return 0;
}