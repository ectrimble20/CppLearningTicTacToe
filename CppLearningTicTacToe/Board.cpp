#include "Board.h"
#include <iostream>


Board::Board()
{
	
}


Board::~Board()
{
}

void Board::MakeMove(int idx, char c)
{
	//find our index
	board[idx] = c;
}

bool Board::IsOccupied(int idx)
{
	if (board[idx] != ' ')
	{
		return true;
	}
	return false;
}


bool Board::WasWinConditionMet()
{
	//There are 8 possible win conditions, this is a bit... crap, but I don't see a good pattern to automate this check
	//fortunately this is just quick array index checking and direct "char" to decimal value conversions so it should be
	//pretty quick even with 8 checks every turn.
	int checkSum = board[0] + board[1] + board[2];
	if (someoneWon(checkSum)) {
		return true;
	}
	checkSum = board[3] + board[4] + board[5];
	if (someoneWon(checkSum)) {
		return true;
	}
	checkSum = board[6] + board[7] + board[8];
	if (someoneWon(checkSum)) {
		return true;
	}
	checkSum = board[0] + board[4] + board[8];
	if (someoneWon(checkSum)) {
		return true;
	}
	checkSum = board[2] + board[4] + board[6];
	if (someoneWon(checkSum)) {
		return true;
	}
	checkSum = board[0] + board[3] + board[6];
	if (someoneWon(checkSum)) {
		return true;
	}
	checkSum = board[1] + board[5] + board[7];
	if (someoneWon(checkSum)) {
		return true;
	}
	checkSum = board[2] + board[5] + board[8];
	if (someoneWon(checkSum)) {
		return true;
	}
	//if all checks failed, nobody won.
	return false;
}

char Board::GetWinner()
{
	return winningPlayer;
}

int Board::GetIndex(int x, int y)
{
	return ((y * 3) + x) - 196;
}

void Board::Draw()
{
	//draw the header
	std::cout << "     1   2   3" << std::endl;
	std::cout << " A   " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
	std::cout << "    ---|---|---" << std::endl;
	std::cout << " B   " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
	std::cout << "    ---|---|---" << std::endl;
	std::cout << " C   " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
}

bool Board::someoneWon(int checkSum)
{
	if (checkSum == 264)
	{
		gameWon = true;
		winningPlayer = 'X';
		return true;
	}
	else if (checkSum == 237)
	{
		gameWon = true;
		winningPlayer = 'O';
		return true;
	}
	else
	{
		return false;
	}
}

/*
char X = 130 * 3 = 390
char O = 117 * 3 = 351  -- got these wrong, X is 88, O is 79

XXX,,,...  0 1 2
,,,XXX...  3 4 5
,,,...XXX  6 7 8
X,,.X.,,X  0 4 8
,,X.X.X,,  2 4 6
X,,X..X,,  0 3 6
,X,,X,,X,  1 5 7
,,X,,X,,X  2 5 8
*/