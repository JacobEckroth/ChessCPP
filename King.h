#pragma once
#include "Piece.h"
class King: public Piece
{
public:
	std::vector<int> showMoves(int row, int col);
	King(char);
};

