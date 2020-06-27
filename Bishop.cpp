#include "Bishop.h"

#include <vector>
#include <iostream>
std::vector<int> Bishop::showMoves(int row, int col) {
	std::vector<int> possibleMoves;

	int temprow = row;
	int tempcol = col;
	while (++temprow < 8 && ++tempcol < 8) {
		possibleMoves.push_back(temprow);
		possibleMoves.push_back(tempcol);
	}
	temprow = row;
	tempcol = col;
	while (--temprow >= 0 && --tempcol >= 0) {
		possibleMoves.push_back(temprow);
		possibleMoves.push_back(tempcol);
	}
	temprow = row;
	tempcol = col;
	while (++temprow < 8 && --tempcol >= 0) {
		possibleMoves.push_back(temprow);
		possibleMoves.push_back(tempcol);
	}
	temprow = row;
	tempcol = col;
	while (++tempcol< 8 && --temprow >= 0) {
		possibleMoves.push_back(temprow);
		possibleMoves.push_back(tempcol);
	}
	return possibleMoves;

}

Bishop::Bishop(char team) {
	pieceType = 'b';
	this->team = team;
}