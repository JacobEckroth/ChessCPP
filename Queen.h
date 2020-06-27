#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	std::vector<int> showMoves(int row, int col,char**);
	Queen(char);
	bool canKeepMoving(std::vector<int>&, int, int, char**);
};

