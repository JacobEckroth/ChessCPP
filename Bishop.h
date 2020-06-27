#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	std::vector<int> showMoves(int row, int col,char**);
	Bishop(char);
	bool canKeepMoving(std::vector<int>& possibleMoves,int row, int col, char**);
};

