#include "King.h"

#include <vector>
#include <iostream>
std::vector<int> King::showMoves(int row, int col,char** boardStatus) {
	std::vector<int> possibleMoves;

	if (row + 1 < 8) {
		if (col + 1 < 8) {
			tryMove(possibleMoves, row + 1, col + 1, boardStatus);
		}
		tryMove(possibleMoves, row + 1, col, boardStatus);
		
		if (col - 1 >= 0) {
			tryMove(possibleMoves, row + 1, col-1, boardStatus);
		}
	}
	if (col + 1 < 8) {
		tryMove(possibleMoves, row, col + 1, boardStatus);

	}
	if (col - 1 >= 0) {
		tryMove(possibleMoves, row, col - 1, boardStatus);
	}
	if (row - 1 >= 0) {
		if (col + 1 < 8) {
			tryMove(possibleMoves, row-1, col + 1, boardStatus);
			
		}
		tryMove(possibleMoves, row - 1, col, boardStatus);
		if (col - 1 >= 0) {
			tryMove(possibleMoves, row - 1, col -1, boardStatus);
		}
	}
	return possibleMoves;
}


void King::tryMove(std::vector<int>& possibleMoves, int row, int col, char** boardStatus) {
	if ((boardStatus[row][col] == 'w' && team == 'b') || (boardStatus[row][col] == 'b' && team == 'w')) {
		possibleMoves.push_back(row);
		possibleMoves.push_back(col);
	
	}else if (boardStatus[row][col] == 'e') {
		possibleMoves.push_back(row);
		possibleMoves.push_back(col);
		
	}
}

King::King(char team){
	pieceType = 'k';
	this->team = team;
}