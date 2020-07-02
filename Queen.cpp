#include "Queen.h"
#include <vector>
#include <iostream>
#include "TextureManager.h"
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

Queen::Queen(char team,int row, int col){
	pieceType = 'q';
	this->row = row;
	this->col = col;
	this->team = team;
	if (team == 'w') {
		pieceTexture = TextureManager::LoadTexture("images/whiteQueen.png");
	}
	else {
		pieceTexture = TextureManager::LoadTexture("images/blackQueen.png");
	}
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = destRect.w = destRect.h = 100;
	destRect.x = col * 100;
	destRect.y = row * 100;
}


Queen::Queen(char team, int row, int col, int sizeMul) {
	pieceType = 'q';
	this->row = row;
	this->col = col;
	this->team = team;
	if (team == 'w') {
		pieceTexture = TextureManager::LoadTexture("images/whiteQueen.png");
	}
	else {
		pieceTexture = TextureManager::LoadTexture("images/blackQueen.png");
	}
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h =  100;
	destRect.w = destRect.h = 100 * sizeMul;
	destRect.x = col * 100;
	destRect.y = row * 100;
}
bool Queen::attemptMove(int newRow, int newCol, char** boardStatus) {
	std::vector<int> possibleMoves = showMoves(row, col, boardStatus);

	for (int i = 0; i < possibleMoves.size() / 2; i++) {
		if (newRow == possibleMoves[i * 2] && newCol == possibleMoves[i * 2 + 1]) {
			return true;
		}
	}
	return false;
}