#include "Queen.h"
#include <vector>
#include <iostream>
std::vector<int> Queen::showMoves(int row, int col, char** boardStatus) {
	std::vector<int> possibleMoves;
	int tempRow = row;
	int tempCol = col;
	while (++tempRow < 8) {
		if (!(canKeepMoving(possibleMoves, tempRow, tempCol, boardStatus))) {
			break;
		}
	
	}
	tempRow = row;
	while (--tempRow >= 0) {
		if (!(canKeepMoving(possibleMoves, tempRow, tempCol, boardStatus))) {
			break;
		}
	}
	tempRow = row;
	while (++tempCol < 8) {
		if (!(canKeepMoving(possibleMoves, tempRow, tempCol, boardStatus))) {
			break;
		}
	}
	tempCol = col;
	while (--tempCol >= 0) {
		if (!(canKeepMoving(possibleMoves, tempRow, tempCol, boardStatus))) {
			break;
		}
	}
	tempCol = col;
	while (++tempRow < 8 && ++tempCol < 8) {
		if (!(canKeepMoving(possibleMoves, tempRow, tempCol, boardStatus))) {
			break;
		}
	}
	tempRow = row;
	tempCol = col;
	while (--tempRow >= 0 && --tempCol >= 0) {
		if (!(canKeepMoving(possibleMoves, tempRow, tempCol, boardStatus))) {
			break;
		}
	}
	tempRow = row;
	tempCol = col;
	while (++tempRow < 8 && --tempCol >= 0) {
		if (!(canKeepMoving(possibleMoves, tempRow, tempCol, boardStatus))) {
			break;
		}
	}
	tempRow = row;
	tempCol = col;
	while (++tempCol < 8 && --tempRow >= 0) {
		if (!(canKeepMoving(possibleMoves, tempRow, tempCol, boardStatus))) {
			break;
		}
	}
	return possibleMoves;

}


bool Queen::canKeepMoving(std::vector<int>& possibleMoves, int row, int col, char** boardStatus) {
	if ((boardStatus[row][col] == 'w' && team == 'b') || (boardStatus[row][col] == 'b' && team == 'w')) {
		possibleMoves.push_back(row);
		possibleMoves.push_back(col);
		return false;
	}
	else if (boardStatus[row][col] == team) {
		return false;
	}
	else if (boardStatus[row][col] == 'e') {
		possibleMoves.push_back(row);
		possibleMoves.push_back(col);
		return true;
	}
}

Queen::Queen(char team){
	pieceType = 'q';
	this->team = team;
}