#include "King.h"

#include <vector>
#include <iostream>
#include "TextureManager.h"
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

King::King(char team,int row, int col){
	this->row = row;
	this->col = col;
	pieceType = 'k';
	this->team = team;
	if (team == 'w') {
		pieceTexture = TextureManager::LoadTexture("images/whiteKing.png");
	}
	else {
		pieceTexture = TextureManager::LoadTexture("images/blackKing.png");
	}
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = destRect.w = destRect.h = 100;
	destRect.x = col * 100;
	destRect.y = row * 100;
}
bool King::attemptMove(int newRow, int newCol, char** boardStatus) {
	std::vector<int> possibleMoves = showMoves(row, col, boardStatus);
	for (int i = 0; i < possibleMoves.size() / 2; i++) {
		if (newRow == possibleMoves[i * 2] && newCol == possibleMoves[ i * 2 + 1]) {
			return true;
		}
	}
	return false;
}