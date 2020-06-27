#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	std::vector<int> showMoves(int row, int col);
	Rook(char);
};

