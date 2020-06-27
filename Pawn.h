#pragma once
#include "Piece.h"
class Pawn: public Piece
{
public:
	std::vector<int> showMoves(int row, int col,char**);
	Pawn(char);
	bool moved() {
		return hasMoved;
	}

private:
	bool hasMoved;
};

