#include "Queen.h"
#include <vector>
#include <iostream>
std::vector<int> Queen::showMoves(int row, int col) {
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
	tempCol = col;
	while (++tempRow < 8 && ++tempCol < 8) {
		possibleMoves.push_back(tempRow);
		possibleMoves.push_back(tempCol);
	}
	tempRow = row;
	tempCol = col;
	while (--tempRow >= 0 && --tempCol >= 0) {
		possibleMoves.push_back(tempRow);
		possibleMoves.push_back(tempCol);
	}
	tempRow = row;
	tempCol = col;
	while (++tempRow < 8 && --tempCol >= 0) {
		possibleMoves.push_back(tempRow);
		possibleMoves.push_back(tempCol);
	}
	tempRow = row;
	tempCol = col;
	while (++tempCol < 8 && --tempRow >= 0) {
		possibleMoves.push_back(tempRow);
		possibleMoves.push_back(tempCol);
	}
	return possibleMoves;
	return possibleMoves;




}

Queen::Queen(char team){
	pieceType = 'q';
	this->team = team;
}