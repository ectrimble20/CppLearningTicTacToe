#pragma once
#include "Board.h"

class Game
{
public:
	Game();
	~Game();
	void Run();
private:
	void StartNewGame();
	bool gameRunning = true;
	bool boardRunning = false;
	Board currentGameBoard;
	unsigned int scoreForX = 0;
	unsigned int scoreForO = 0;
	bool playerOne = true;

	void printTurnMenu();
	void printGameMenu();
	void printPlayAgain();
	void getUserMove();
	void processUserMenuRequest();
	void processPlayAgain();
};

