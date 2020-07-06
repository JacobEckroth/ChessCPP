#include "Bishop.h"
#include "TextureManager.h"
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

Bishop::Bishop(char team,int row, int col) {
	pieceType = 'b';
	this->team = team;
	this->row = row;
	this->col = col;
	if (team == 'w') {
		pieceTexture = TextureManager::LoadTexture("images/whiteBishop.png");
	}
	else {
		pieceTexture = TextureManager::LoadTexture("images/blackBishop.png");
	}
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h  = 100;
	destRect.w = Board::boxWidth;
	destRect.h = Board::boxHeight;
	destRect.x = col * Board::boxWidth;
	destRect.y = row * Board::boxHeight;
}

Bishop::Bishop(char team, int row, int col, int sizeMul) {
	pieceType = 'b';
	this->team = team;
	this->row = row;
	this->col = col;
	if (team == 'w') {
		pieceTexture = TextureManager::LoadTexture("images/whiteBishop.png");
	}
	else {
		pieceTexture = TextureManager::LoadTexture("images/blackBishop.png");
	}
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 100;
	destRect.w = Board::boxWidth * sizeMul;
	destRect.h = Board::boxHeight * sizeMul;
	destRect.x = col * Board::boxWidth;
	destRect.y = row * Board::boxHeight;
}

bool Bishop::attemptMove(int newRow, int newCol,char** boardStatus) {
	std::vector<int> possibleMoves = showMoves(row, col, boardStatus);

	for (int i = 0; i < possibleMoves.size() / 2; i++) {
		if (newRow == possibleMoves[i * 2] && newCol == possibleMoves[i * 2 + 1]) {
			return true;
		}
	}
	return false;
}