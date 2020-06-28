#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	std::vector<int> showMoves(int row, int col,char**);
	Bishop(char,int,int);
	bool canKeepMoving(std::vector<int>& possibleMoves,int row, int col, char**);
	bool attemptMove(int row, int col,char**);
};

