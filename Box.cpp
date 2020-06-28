#include "Box.h"
#include "Board.h"
#include "SDL.h"
#include "Game.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include <iostream>
int lightTan[3] = { 255,206,158 };
int darkTan[3] = { 209,139,71};



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
		originalColor[0] = currentColor[0] = lightTan[0];
		originalColor[1] = currentColor[1] = lightTan[1];
		originalColor[2] = currentColor[2] = lightTan[2];

	}
	else {
		originalColor[0] = currentColor[0] = darkTan[0];
		originalColor[1] = currentColor[1] = darkTan[1];
		originalColor[2] = currentColor[2] = darkTan[2];
	}
	isHighlighted = false;
	
}

bool Box::highlighted() {
	return isHighlighted;
}

void Box::toggleHighlight(char currentPlayer) {
	if (!isHighlighted) {
		isHighlighted = true;
		if (originalColor[0] == lightTan[0]) {
			if (getPiece()) {
				if (getPiece()->getTeam() != currentPlayer) {
					currentColor[0] = 248;
					currentColor[1] = 138;
					currentColor[2] = 112;
				}
				
			}
			else {
				currentColor[0] = 154;
				currentColor[1] = 190;
				currentColor[2] = 134;
			}
		
		}
		else {
			if (getPiece()) {
				if (getPiece()->getTeam() != currentPlayer) {
					currentColor[0] = 220;
					currentColor[1] = 97;
					currentColor[2] = 58;
				
				}
			}else {
					currentColor[0] = 130;
					currentColor[1] = 159;
					currentColor[2] = 90;
			}

			
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

	piece = newPiece;
};

void Box::removePiece() {
	if (piece) {
		free(piece);
		piece = nullptr;
	}
}