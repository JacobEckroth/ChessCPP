#pragma once
#include "Piece.h"
class Knight: public Piece
{
public:
	std::vector<int> showMoves(int row, int col,char**);
	Knight(char);
	void testMove(std::vector<int>&, int, int,char**);
};

