#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	std::vector<int> showMoves(int row, int col,char**);
	Rook(char, int row, int col);
	Rook(char, int, int, int);
	bool areWeDone(std::vector<int>& possibleMoves, char** boardStatus, int tempRow, int tempCol);
	bool attemptMove(int row, int col,char**);
};

