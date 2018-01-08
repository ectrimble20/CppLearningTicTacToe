#pragma once
#include <vector>
#include <string>

class Board
{
public:
	Board();
	~Board();
	void MakeMove(int idx, char c);
	bool IsOccupied(int idx);
	bool WasWinConditionMet();
	char GetWinner();
	int GetIndex(int x, int y);
	void Draw();
private:
	char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	unsigned int movesLeft = 9; //maximum possible moves
	bool gameWon = false;
	char winningPlayer = ' ';
	bool someoneWon(int checkSum);
};

