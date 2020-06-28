#include "Rook.h"
#include "TextureManager.h"
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

Rook::Rook(char team,int row, int col) {
	this->row = row;
	this->col = col;
	this->team = team;
	pieceType = 'r';
	if (team == 'w') {
		pieceTexture = TextureManager::LoadTexture("images/whiteRook.png");
	}
	else {
		pieceTexture = TextureManager::LoadTexture("images/blackRook.png");
	}
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = destRect.w = destRect.h = 100;
	destRect.x = col * 100;
	destRect.y = row * 100;



}
bool Rook::attemptMove(int newRow, int newCol, char** boardStatus) {
	std::vector<int> possibleMoves = showMoves(row, col, boardStatus);

	for (int i = 0; i < possibleMoves.size() / 2; i++) {
		if (newRow == possibleMoves[i * 2] && newCol == possibleMoves[i * 2 + 1]) {
			return true;
		}
	}
	return false;
}