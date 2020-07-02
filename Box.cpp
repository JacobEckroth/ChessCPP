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
	isHighlighted = false;
	destRect.x = col * Board::boxWidth;
	destRect.y = row * Board::boxHeight;
	destRect.w = Board::boxWidth;
	destRect.h = Board::boxHeight;
	isTargeted = false;
	
	
}

bool Box::highlighted() {
	return isHighlighted;
}

void Box::toggleHighlight(char currentPlayer) {
	
	isHighlighted == true ? isHighlighted = false : isHighlighted = true;

	char enemyPlayer;
	currentPlayer == 'w' ? enemyPlayer = 'b' : enemyPlayer = 'w';

	if (isHighlighted) {
		if (getPiece()) {
			if (getPiece()->getTeam() == enemyPlayer) {
				r = 255;
				g = 0;
				b= 0;
				a= 50;
			}
			else {
				r = 0;
					g = 255;
					b = 0;
					a = 50;
			}
		}
		else {
			r= 0;
			g = 255;
			b = 0;
			a = 50;
		}
	}
}

void Box::render() {
	//error is not here
	
	if (isHighlighted) {
		
		SDL_SetRenderDrawColor(Game::renderer,r,g,b,a);
		SDL_RenderFillRect(Game::renderer, &destRect);
		
	}
	else if (isTargeted) {
		
		SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 100);
		SDL_RenderFillRect(Game::renderer, &destRect);

	}
}
Box::Box() {
	
}
Box::~Box() {
	if (piece) {
		delete(piece);
	}

	
}

void Box::setPiece(Piece* newPiece) {

	piece = newPiece;
};

void Box::removePiece() {
	if (piece) {
		delete piece;
		piece = nullptr;
	}
}

void Box::toggleTargeted(bool newTargeted) {
	isTargeted = newTargeted;

}