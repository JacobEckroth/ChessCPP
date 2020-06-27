#include "King.h"

#include <vector>
#include <iostream>
std::vector<int> King::showMoves(int row, int col) {
	std::vector<int> possibleMoves;

	if (row + 1 < 8) {
		if (col + 1 < 8) {
			possibleMoves.push_back(row + 1);
			possibleMoves.push_back(col + 1);
		}
		possibleMoves.push_back(row + 1);
		possibleMoves.push_back(col);
		if (col - 1 >= 0) {
			possibleMoves.push_back(row + 1);
			possibleMoves.push_back(col - 1);
		}
	}
	if (col + 1 < 8) {
		possibleMoves.push_back(row);
		possibleMoves.push_back(col + 1);

	}
	if (col - 1 >= 0) {
		possibleMoves.push_back(row);
		possibleMoves.push_back(col - 1);
	}
	if (row - 1 >= 0) {
		if (col + 1 < 8) {
			possibleMoves.push_back(row - 1);
			possibleMoves.push_back(col + 1);
		}
		possibleMoves.push_back(row - 1);
		possibleMoves.push_back(col);
		if (col - 1 >= 0) {
			possibleMoves.push_back(row - 1);
			possibleMoves.push_back(col - 1);
		}
	}




	return possibleMoves;
}

King::King(char team){
	pieceType = 'k';
	this->team = team;
}