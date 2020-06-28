#include "Pawn.h"
#include <vector>
#include <iostream>
#include "TextureManager.h"
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
Pawn::Pawn(char team,int row, int col) {
	this->row = row;
	this->col = col;
	pieceType = 'p';
	this->team = team;
	hasMoved = false;
	if (team == 'w') {
		pieceTexture = TextureManager::LoadTexture("images/whitePawn.png");
	}
	else {
		pieceTexture = TextureManager::LoadTexture("images/blackPawn.png");
	}
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = destRect.w = destRect.h = 100;
	destRect.x = col * 100;
	destRect.y = row * 100;
}


bool Pawn::attemptMove(int newRow, int newCol, char** boardStatus) {
	std::vector<int> possibleMoves = showMoves(row, col, boardStatus);

	for (int i = 0; i < possibleMoves.size() / 2; i++) {
		if (newRow == possibleMoves[i * 2] && newCol == possibleMoves[i * 2 + 1]) {
			return true;
		}
	}
	return false;
}

