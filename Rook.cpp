#include "Rook.h"

#include <vector>
#include <iostream>
std::vector<int> Rook::showMoves(int row, int col,char** boardStatus) {
	std::vector<int> possibleMoves;
	int tempRow = row;
	int tempCol = col;
	while (++tempRow < 8) {
		if (areWeDone(possibleMoves, boardStatus, tempRow, tempCol)) {
			break;
		}
	}
	tempRow = row;
	while (--tempRow >= 0) {
		if (areWeDone(possibleMoves, boardStatus, tempRow, tempCol)) {
			break;
		}
	}
	tempRow = row;
	while (++tempCol < 8) {
		if (areWeDone(possibleMoves, boardStatus, tempRow, tempCol)) {
			break;
		}
	}
	tempCol = col;
	while (--tempCol >= 0) {
		if (areWeDone(possibleMoves, boardStatus, tempRow, tempCol)) {
			break;
		}
	}


	return possibleMoves;
}


//tests if the rook can move onto the square it is passed.
bool Rook::areWeDone(std::vector<int>& possibleMoves,char**boardStatus,int tempRow, int tempCol) {
	if (boardStatus[tempRow][tempCol] == 'w' && team == 'w') {
		return true;
	}
	else if (boardStatus[tempRow][tempCol] == 'b' && team == 'b') {
		return true;
	}
	else if (boardStatus[tempRow][tempCol] == 'w' && team == 'b') {
		possibleMoves.push_back(tempRow);
		possibleMoves.push_back(tempCol);
		return true;
	}
	else if (boardStatus[tempRow][tempCol] == 'b' && team == 'w') {
		possibleMoves.push_back(tempRow);
		possibleMoves.push_back(tempCol);
		return true;
	}
	possibleMoves.push_back(tempRow);
	possibleMoves.push_back(tempCol);
	return false;
}

Rook::Rook(char team) {
	this->team = team;
	pieceType = 'r';
}