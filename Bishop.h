#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	std::vector<int> showMoves(int row, int col);
	Bishop(char);
};

