#pragma once
#include "Piece.h"
class King: public Piece
{
public:
	std::vector<int> showMoves(int row, int col,char**);
	King(char,int,int);
	void tryMove(std::vector<int>&, int row, int col, char**);
};

