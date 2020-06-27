#include "Rook.h"

#include <vector>
#include <iostream>
std::vector<int> Rook::showMoves(int row, int col) {
	std::vector<int> possibleMoves;
	int tempRow = row;
	int tempCol = col;
	while (++tempRow < 8) {
		possibleMoves.push_back(tempRow);
		possibleMoves.push_back(tempCol);
	}
	tempRow = row;
	while (--tempRow >= 0) {
		possibleMoves.push_back(tempRow);
		possibleMoves.push_back(tempCol);
	}
	tempRow = row;
	while (++tempCol < 8) {
		possibleMoves.push_back(tempRow);
		possibleMoves.push_back(tempCol);
	}
	tempCol = col;
	while (--tempCol >= 0) {
		possibleMoves.push_back(tempRow);
		possibleMoves.push_back(tempCol);
	}


	return possibleMoves;




}

Rook::Rook(char team) {
	this->team = team;
	pieceType = 'r';
}