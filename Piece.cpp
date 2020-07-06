#include "Piece.h"
#include "Game.h"
#include <iostream>
char Piece::getType() {
	return pieceType;
}
 

char Piece::getTeam() {
	return team;
}

void Piece::render() {
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	SDL_RenderCopy(Game::renderer, pieceTexture, &srcRect, &destRect);
}

void Piece::drawToMouse() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	destRect.x = x - Board::boxWidth/2;
	destRect.y = y - Board::boxHeight/2;
	
	pickedUp = true;
}
void Piece::resetPlace() {
	destRect.x = col * (Board::boxWidth);
	destRect.y = row * Board::boxHeight;
}
Piece::~Piece() {
	if (pieceTexture) {
		
		SDL_DestroyTexture(pieceTexture);
	}
	
}