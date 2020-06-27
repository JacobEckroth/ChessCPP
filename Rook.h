#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	std::vector<int> showMoves(int row, int col,char**);
	Rook(char);
	bool areWeDone(std::vector<int>& possibleMoves, char** boardStatus, int tempRow, int tempCol);
};

