#include "Game.h"
#include <iostream>


Game::Game()
{
}


Game::~Game()
{
}

void Game::StartNewGame()
{
	//reset the board
	currentGameBoard = Board();
}

void Game::Run()
{
	while (gameRunning)
	{
		//first see if we're actually in the middle of a game
		if (boardRunning)
		{
			currentGameBoard.Draw();
			printTurnMenu();
			getUserMove();
			if (currentGameBoard.WasWinConditionMet())  //this isn't working
			{
				char winner = currentGameBoard.GetWinner();
				if (winner == 'X') {
					std::cout << "X has won the game!" << std::endl;
					scoreForX += 1;
				}
				else if (winner == 'O')
				{
					std::cout << "O has won the game!" << std::endl;
					scoreForO += 1;
				}
				else
				{
					std::cout << "Winning condition was met, but we didn't get a valid winner back from the board :(" << std::endl;
				}
				//okay, a game was won, see if we want to play again
				printPlayAgain();
				processPlayAgain();
			}
		}
		else
		{
			printGameMenu();
			//TODO need a function to grab and process the users request
			processUserMenuRequest();
		}
	}
}

void Game::printTurnMenu()
{
	std::cout << "Score  -  X: " << scoreForX << ",  O: " << scoreForO << std::endl;
	std::cout << "It is ";
	if (playerOne) {
		std::cout << " X";
	}
	else
	{
		std::cout << " O";
	}
	std::cout << "'s turn, please enter your move below." << std::endl;
}

void Game::printGameMenu()
{
	std::cout << "-=TicTacToe=-" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "(N)ew game" << std::endl;
	std::cout << "(Q)uit game" << std::endl;
}

void Game::printPlayAgain()
{
	std::cout << "Would you like to play again? (Y)es/(N)o" << std::endl;
}

void Game::getUserMove()
{
	bool inputComplete = false;
	char row = ' ';
	int col = 0;
	while (!inputComplete) {
		if (row == ' ') {
			//alright, we need to get a row and a column
			std::cout << "Enter Row(A-C): ";
			std::cin >> row;
			//check if we got a lower case char
			if (row > 96) {
				//if we did, we can convert to upper case by simply subtracting 32
				row = row - 32;
			}
			//need to validate our input
			if (row > 'C' || row < 'A')
			{
				std::cout << "You entered " << row << " which is not valid." << std::endl;
				continue;
			}
		}
		if (col == 0)
		{
			std::cout << "Enter Column(1-3): ";
			std::cin >> col;
			if (col > 3 || col < 1) {
				std::cout << "You entered " << col << " which is not valid." << std::endl;
				continue;
			}
		}
		//lastly, we want to check that the position is free
		if (currentGameBoard.IsOccupied(currentGameBoard.GetIndex(col, row)))
		{
			std::cout << "The position you entered (" << col << "," << row << ") is occupied, please try again" << std::endl;
			row = ' ';
			col = 0;
			continue;
		}
		inputComplete = true; //exit loop
	}
	char p;
	if (playerOne) {
		p = 'X';
	}
	else
	{
		p = 'O';
	}
	currentGameBoard.MakeMove(currentGameBoard.GetIndex(col, row), p);
	//switch the player
	playerOne = !playerOne;
}

void Game::processUserMenuRequest()
{
	bool goodInput = false;
	while (!goodInput)
	{
		char userIn;
		std::cin >> userIn;
		//valid input is N/n or Q/q
		if (userIn != 'n' && userIn != 'N' && userIn != 'q' && userIn != 'Q')
		{
			std::cout << "Invalid input, " << userIn << " is not a valid choice." << std::endl;
		}
		else
		{
			goodInput = true;
			if (userIn == 'n' || userIn == 'N')
			{
				boardRunning = true;
				StartNewGame();
			}
			else
			{
				gameRunning = false;
			}
		}
	}
}

void Game::processPlayAgain()
{
	bool goodInput = false;
	while (!goodInput)
	{
		char i;
		std::cin >> i;
		if (i == 'Y' || i == 'y' || i == 'N' || i == 'n')
		{
			goodInput = true;
			if (i == 'Y' || i == 'y')
			{
				StartNewGame();
			}
			else
			{
				gameRunning = false;
			}
		}
		else
		{
			std::cout << "Invalid input, please try again" << std::endl;
		}
	}
}
