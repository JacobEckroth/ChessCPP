#include "Knight.h"
#include <vector>
#include <iostream>
std::vector<int> Knight::showMoves(int row, int col) {
	std::vector<int> possibleMoves;
	

	if (!(row + 2 >= 8)) {
		if (!(col + 1 >= 8)) {
			possibleMoves.push_back(row + 2);
			possibleMoves.push_back(col + 1);
		}
		if (!(col - 1 < 0)) {
			possibleMoves.push_back(row + 2);
			possibleMoves.push_back(col - 1);
		}
	}
	if (!(row -2 <0)) {
		if (!(col + 1 >= 8)) {
			possibleMoves.push_back(row - 2);
			possibleMoves.push_back(col + 1);
		}
		if (!(col - 1 < 0)) {
			possibleMoves.push_back(row - 2);
			possibleMoves.push_back(col - 1);
		}
	}
	if (!(col + 2 >= 8)) {
		if (!(row + 1 >= 8)) {
			possibleMoves.push_back(row + 1);
			possibleMoves.push_back(col + 2);
		}
		if (!(row-1 < 0)) {
			possibleMoves.push_back(row - 1);
			possibleMoves.push_back(col + 2);
		}
	}
	if (!(col - 2 < 0)) {
		if (!(row + 1 >= 8)) {
			possibleMoves.push_back(row + 1);
			possibleMoves.push_back(col - 2);
		}
		if (!(row - 1 < 0)) {
			possibleMoves.push_back(row - 1);
			possibleMoves.push_back(col - 2);
		}
	}
	return possibleMoves;
	



}

Knight::Knight(char team) {
	pieceType = 'k';
	this->team = team;
}