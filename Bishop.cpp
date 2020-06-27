#include "Bishop.h"

#include <vector>
#include <iostream>
std::vector<int> Bishop::showMoves(int row, int col, char** boardStatus) {
	std::vector<int> possibleMoves;

	int temprow = row;
	int tempcol = col;
	while (++temprow < 8 && ++tempcol < 8) {
		if (!canKeepMoving(possibleMoves, temprow, tempcol, boardStatus)) {
			break;
		}
	}
	temprow = row;
	tempcol = col;
	while (--temprow >= 0 && --tempcol >= 0) {
		if (!canKeepMoving(possibleMoves, temprow, tempcol, boardStatus)) {
			break;
		}
	}
	temprow = row;
	tempcol = col;
	while (++temprow < 8 && --tempcol >= 0) {
		if (!canKeepMoving(possibleMoves, temprow, tempcol, boardStatus)) {
			break;
		}
	}
	temprow = row;
	tempcol = col;
	while (++tempcol < 8 && --temprow >= 0) {
		if (!canKeepMoving(possibleMoves, temprow, tempcol, boardStatus)) {
			break;
		}
	}
	return possibleMoves;

}

bool Bishop::canKeepMoving(std::vector<int>& possibleMoves, int row, int col, char** boardStatus) {
	if ((boardStatus[row][col] == 'w' && team == 'b') || (boardStatus[row][col] == 'b' && team == 'w')) {
		possibleMoves.push_back(row);
		possibleMoves.push_back(col);
		return false;
	} else if (boardStatus[row][col] == team){
		return false;
	}
	else if (boardStatus[row][col] == 'e') {
		possibleMoves.push_back(row);
		possibleMoves.push_back(col);
		return true;
	}
}

Bishop::Bishop(char team) {
	pieceType = 'b';
	this->team = team;
}