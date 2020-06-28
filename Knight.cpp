#include "Knight.h"
#include "TextureManager.h"
#include <vector>
#include <iostream>
std::vector<int> Knight::showMoves(int row, int col,char** boardStatus) {
	std::vector<int> possibleMoves;
	if (!(row + 2 >= 8)) {
		if (!(col + 1 >= 8)) {
			testMove(possibleMoves, row + 2, col + 1, boardStatus);
		}
		if (!(col - 1 < 0)) {
			testMove(possibleMoves, row + 2, col - 1, boardStatus);
		}
	}
	if (!(row -2 <0)) {
		if (!(col + 1 >= 8)) {
			testMove(possibleMoves, row - 2, col + 1, boardStatus);
		}
		if (!(col - 1 < 0)) {
			testMove(possibleMoves, row - 2, col - 1, boardStatus);
		}
	}
	if (!(col + 2 >= 8)) {
		if (!(row + 1 >= 8)) {
			testMove(possibleMoves, row + 1, col + 2, boardStatus);
		}
		if (!(row-1 < 0)) {
			testMove(possibleMoves, row - 1, col + 2, boardStatus);
		}
	}
	if (!(col - 2 < 0)) {
		if (!(row + 1 >= 8)) {
			testMove(possibleMoves, row + 1, col - 2, boardStatus);
		}
		if (!(row - 1 < 0)) {
			testMove(possibleMoves, row - 1, col - 2, boardStatus);
		}
	}
	return possibleMoves;
	



}

void Knight::testMove(std::vector<int>& possibleMoves, int row, int col,char** boardStatus) {

	if (boardStatus[row][col] == 'e' || (boardStatus[row][col] == 'w' && team == 'b') || (boardStatus[row][col] == 'b' && team == 'w')) {
		possibleMoves.push_back(row);
		possibleMoves.push_back(col);
	}
}

Knight::Knight(char team,int row, int col) {
	pieceType = 'k';
	this->row = row;
	this->col = col;
	this->team = team;
	if (team == 'w') {
		pieceTexture = TextureManager::LoadTexture("images/whiteKnight.png");
	}
	else {
		pieceTexture = TextureManager::LoadTexture("images/blackKnight.png");
	}
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = destRect.w = destRect.h = 100;
	destRect.x = col * 100;
	destRect.y = row * 100;
}