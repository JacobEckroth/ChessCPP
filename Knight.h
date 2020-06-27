#pragma once
#include "Piece.h"
class Knight: public Piece
{
public:
	std::vector<int> showMoves(int row, int col);
	Knight(char);
};

