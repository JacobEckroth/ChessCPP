#pragma once
#include "Piece.h"
class Pawn: public Piece
{
public:
	std::vector<int> showMoves(int row, int col,char**);
	Pawn(char,int,int);
	bool attemptMove(int row, int col,char**);
	bool recentlyMoved() {
		return justMoved;
	};
	void setJustMoved(bool setter) {
		justMoved = setter;
	}
private:
	bool justMoved;
};

