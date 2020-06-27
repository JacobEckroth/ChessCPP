#include "Pawn.h"
#include <vector>
#include <iostream>
std::vector<int> Pawn::showMoves(int row, int col,char** boardStatus) {
	std::vector<int> possibleMoves;
	if (team == 'w') {
		if (row - 1 >= 0 && boardStatus[row-1][col] == 'e') {
			possibleMoves.push_back(row - 1);
			possibleMoves.push_back(col);

		}
		if (!hasMoved && boardStatus[row-2][col] == 'e' && boardStatus[row-1][col] == 'e') {
			possibleMoves.push_back(row - 2);
			possibleMoves.push_back(col);
		}

		//diagonal attacks
		if (row - 1 >= 0 && boardStatus[row - 1][col - 1] == 'b') {
			possibleMoves.push_back(row - 1);
			possibleMoves.push_back(col - 1);
		}
		if (row - 1 >= 0 && boardStatus[row - 1][col +1] == 'b') {
			possibleMoves.push_back(row - 1);
			possibleMoves.push_back(col + 1);
		}

	}
	else { //black pawns
		if (row + 1 < 8 && boardStatus[row+1][col] == 'e') {
			possibleMoves.push_back(row + 1);
			possibleMoves.push_back(col);
		}
		if (!hasMoved && boardStatus[row+2][col] == 'e' && boardStatus[row + 1][col] == 'e') {
			possibleMoves.push_back(row + 2);
			possibleMoves.push_back(col);
		}
		//diagonal attacks
		if (row + 1 < 8 && boardStatus[row + 1][col - 1] == 'w') {
			possibleMoves.push_back(row + 1);
			possibleMoves.push_back(col - 1);
		}
		if (row + 1 < 8 && boardStatus[row + 1][col + 1] == 'w') {
			possibleMoves.push_back(row + 1);
			possibleMoves.push_back(col + 1);
		}
		
	}
	return possibleMoves;
}
Pawn::Pawn(char team) {
	pieceType = 'p';
	this->team = team;
	hasMoved = false;
}