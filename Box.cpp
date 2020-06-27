#include "Box.h"
#include "Board.h"
#include "SDL.h"
#include "Game.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include <iostream>
int Box::getRow() {
	return row;
}
int Box::getCol() {
	return col;
}
Box::Box(int row, int col) {
	piece = NULL;
	this->row = row;
	this->col = col;
	if ((row + col) % 2 == 0) { //this works to detect every other row. Kinda guessed on this one.
		originalColor[0] = originalColor[1] = originalColor[2] = currentColor[0] = currentColor[1] = currentColor[2] = 255;
	}
	else {
		originalColor[0] = originalColor[2] = originalColor[1] = currentColor[0] = currentColor[1] =currentColor[2]= 0;
	}
	isHighlighted = false;
	
}

bool Box::highlighted() {
	return isHighlighted;
}

void Box::toggleHighlight() {
	if (!isHighlighted) {
		isHighlighted = true;
		if (originalColor[0] == 0) {
			currentColor[0] = 25;
			currentColor[1] = 85;
			currentColor[2] = 53;
		}
		else {
			currentColor[0] = 154;
			currentColor[1] = 215;
			currentColor[2] = 183;
		}
		
	}
	else {
		isHighlighted = false;
		currentColor[0] = originalColor[0];
		currentColor[1] = originalColor[1];
		currentColor[2] = originalColor[2];
	}


}

void Box::render() {
	SDL_Rect rect;
	rect.x = col * Board::boxWidth;
	rect.y = row * Board::boxHeight;
	rect.w = Board::boxWidth;
	rect.h = Board::boxHeight;

	SDL_SetRenderDrawColor(Game::renderer, currentColor[0], currentColor[1], currentColor[2], 255);
	SDL_RenderFillRect(Game::renderer, &rect);
}
Box::Box() {
	
}
Box::~Box() {
	if (piece) {
		free(piece);
	}
}

void Box::setPiece(Piece* newPiece) {

	if (piece) {
		free(piece);
		piece = nullptr;
	}
	piece = newPiece;
};

void Box::removePiece() {
	if (piece) {
		free(piece);
		piece = nullptr;
	}
	
	
}